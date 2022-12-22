/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:50:14 by yejinkim          #+#    #+#             */
/*   Updated: 2022/09/14 15:15:31 by yejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_ptrlen(unsigned long long n)
{
	int	len;

	len = 2;
	if (n == 0)
		return (++len);
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

void	ft_puthex(unsigned int n, char format)
{
	if (n > 15)
		ft_puthex(n / 16, format);
	if (format == 'X')
		write(1, &"0123456789ABCDEF"[n % 16], 1);
	else if (format == 'x')
		write(1, &"0123456789abcdef"[n % 16], 1);
}

void	ft_putptr(unsigned long long n)
{
	if (n > 15)
		ft_putptr(n / 16);
	write(1, &"0123456789abcdef"[n % 16], 1);
}

int	print_hex(char format, va_list ap)
{
	unsigned long long	hex;

	hex = (unsigned long long)va_arg(ap, void *);
	if (format == 'p')
	{
		write(1, "0x", 2);
		ft_putptr(hex);
		return (ft_ptrlen(hex));
	}
	else if (format == 'x' || format == 'X')
	{
		ft_puthex(hex, format);
		return (ft_hexlen(hex));
	}
	return (0);
}
