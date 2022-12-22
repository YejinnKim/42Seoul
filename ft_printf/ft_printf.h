/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinkim <yejinkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:04:32 by yejinkim          #+#    #+#             */
/*   Updated: 2022/09/13 22:19:57 by yejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		print_hex(char format, va_list ap);
void	ft_puthex(unsigned int n, char format);
void	ft_putptr(unsigned long long n);
int		ft_hexlen(unsigned int n);
int		ft_ptrlen(unsigned long long n);
int		print_num(char format, va_list ap);
void	ft_putnbr_unsigned(unsigned int n);
void	ft_putnbr(int n);
int		ft_nbrlen(long n);
int		print_str(char format, va_list ap);
int		ft_putstr(char *s);
int		ft_putchar(char c);

#endif
