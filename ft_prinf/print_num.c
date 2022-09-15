/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:13:23 by yejinkim          #+#    #+#             */
/*   Updated: 2022/09/14 15:15:34 by yejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbr(int n)
{
	long	nb;
	char	tmp;

	nb = n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	tmp = (nb % 10) + '0';
	write(1, &tmp, 1);
}

void	ft_putnbr_unsigned(unsigned int n)
{
	char	tmp;

	if (n > 9)
		ft_putnbr(n / 10);
	tmp = (n % 10) + '0';
	write(1, &tmp, 1);
}

int	print_num(char format, va_list ap)
{
	int	num;

	num = va_arg(ap, int);
	if (format == 'd' || format == 'i')
	{
		ft_putnbr(num);
		return (ft_nbrlen(num));
	}
	else if (format == 'u')
	{
		ft_putnbr_unsigned((unsigned int)num);
		return (ft_nbrlen((unsigned int)num));
	}
	return (0);
}
