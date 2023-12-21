/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writers_selector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:09:10 by antcampo          #+#    #+#             */
/*   Updated: 2023/11/17 08:03:40 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c, int *total_len)
{
	if (write(1, &c, 1) == -1)
		*total_len = -1;
	else
		*total_len += 1;
}

void	ft_putstr(char *s, int *total_len)
{
	int	s_size;

	if (!s)
	{
		if (write(1, "(null)", 6) == -1)
			*total_len = -1;
		else
			*total_len += 6;
		return ;
	}
	s_size = ft_strlen(s);
	if (write(1, s, s_size) == -1)
	{
		*total_len = -1;
		return ;
	}
	else
		*total_len += s_size;
}

void	select_writer(char type, va_list valist, int *len)
{
	if (type == 'c')
		ft_putchar(va_arg(valist, int), len);
	else if (type == 's')
		ft_putstr(va_arg(valist, char *), len);
	else if (type == 'p')
		ft_putptr(va_arg(valist, unsigned long long), len);
	else if (type == 'd' || type == 'i')
		ft_putnbr(va_arg(valist, int), len);
	else if (type == 'u')
		ft_putunbr(va_arg(valist, unsigned int), len);
	else if (type == 'x')
		ft_puthex(va_arg(valist, unsigned int), "0123456789abcdef", len);
	else if (type == 'X')
		ft_puthex(va_arg(valist, unsigned int), "0123456789ABCDEF", len);
	else if (type == '%')
		ft_putchar('%', len);
	else
		*len = -1;
}
