/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:03:47 by yejinkim          #+#    #+#             */
/*   Updated: 2022/09/14 16:10:40 by yejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = -1;
	len = 0;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i++] == '%')
		{
			if (format[i] == 'c' || format[i] == 's' || format[i] == '%')
				len += print_str(format[i], ap);
			else if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
				len += print_num(format[i], ap);
			else if (format[i] == 'p' || format[i] == 'x' || format[i] == 'X')
				len += print_hex(format[i], ap);
			else
				return (-1);
		}
		else
			len += ft_putchar(format[--i]);
	}
	va_end(ap);
	return (len);
}
