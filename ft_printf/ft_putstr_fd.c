/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:24:59 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/27 18:29:16 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	num = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = -n;
	}
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	ft_putchar_fd(num % 10 + '0', fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s != 0)
		write(fd, s, ft_strlen(s));
}

void	ft_puthex(int num, int mode)
{
	char	c;
	char	to_print;
	char	*hex;

	c = num - '0';
	if (mode == 1)
		hex = "0123456789abcdef";
	else if (mode == 2)
		hex = "0123456789ABCDEF";
	if (mode == 0)
	{
		to_print = hex[c / 16];
		write(1, &to_print, 1);
		to_print = hex[c % 16];
		write(1, &to_print, 1);
	}
	else if (mode == 1)
		write(1, &c, 1);
}
