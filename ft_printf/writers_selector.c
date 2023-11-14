/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writers_selector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:09:10 by antcampo          #+#    #+#             */
/*   Updated: 2023/11/14 11:51:53 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}

int	ft_putchar(char c, int *total_len)
{
	if (write(1, &c, 1) == -1)
	{
		*total_len = -1;
		return (-1);
	}
	*total_len += 1;
	return (1);
}

int	ft_putstr(char *s, int *total_len)
{
	int	s_size;

	if (!s)
	{
		write(1, "(null)", 6);
		*total_len += 6;
		return (1);
	}
	s_size = ft_strlen(s);
	if (write(1, s, s_size) == -1)
		return (-1);
	*total_len += s_size;
	return (1);
}

void	select_writer(char type, va_list valist, int *len)
{
	int	result;

	result = 0;
	if (type == 'c')
		result = ft_putchar(va_arg(valist, int), len);
	else if (type == 's')
		result = ft_putstr(va_arg(valist, char *), len);
	else if (type == 'p')
		result = ft_putptr(va_arg(valist, void *), len);
	else if (type == 'd' || type == 'i')
		result = ft_putnbr(va_arg(valist, int), len);
	else if (type == 'u')
		result = ft_putunbr(va_arg(valist, unsigned int), len);
	else if (type == 'x')
		result = ft_puthex(va_arg(valist, unsigned int), "0123456789abcdef", len);
	else if (type == 'X')
		result = ft_puthex(va_arg(valist, unsigned int), "0123456789ABCDEF", len);
	else if (type == '%')
		result = ft_putchar('%', len);
	else
		*len = -1;
}
