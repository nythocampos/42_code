/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writers_selector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:09:10 by antcampo          #+#    #+#             */
/*   Updated: 2023/10/26 15:32:45 by antcampo         ###   ########.fr       */
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
	if (c == '\0')
		return (-1);
	write(1, &c, 1);
	*total_len += 1;
	return (1);
}

int	ft_putstr(char *s, int *total_len)
{
	int	s_size;

	if (!s)
		return (-1);
	write(1, s, s_size);
	*total_len += s_size;
	return (1);
}

int	select_writer(char type, va_list valist, int *len)
{
	int	result;

	result = 0;
	if (type == 'c')
		result = ft_putchar((char) va_arg(valist, int), len);
	if (type == 's')
		result = ft_putstr((char *) va_arg(valist, char *), len);
	if (type == 'p')
		result = ft_putptr((void *) va_arg(valist, void *), len);
	if (type == 'd' || type == 'i')
		result = ft_putnbr((int) va_arg(valist, int), len);
	if (type == 'u')
		result = ft_putunbr((unsigned int) va_arg(valist, unsigned int), len);
	if (type == 'x')
		result = ft_puthex((int) va_arg(valist, int), "0123456789abcdef", len);
	if (type == 'X')
		result = ft_puthex((int) va_arg(valist, int), "0123456789ABCDEF", len);
	if (type == '%')
		result = ft_putchar('%', len);
	return (result);
}
