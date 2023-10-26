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

void	select_writer(char type, va_list valist, int *len)
{
	if (type == 'c')
		*len = ft_putchar((char) va_arg(valist, int));
	if (type == 's')
		*len = ft_putstr((char *) va_arg(valist, char *));
	if (type == 'p')
		*len = ft_putptr((void *) va_arg(valist, void *));
	if (type == 'd')
		*len = ft_putnbr((int) va_arg(valist, int));
	if (type == 'i')
		*len = ft_putnbr((int) va_arg(valist, int));
	if (type == 'u')
		*len = ft_putunbr((unsigned int) va_arg(valist, unsigned int));
	if (type == 'x')
		*len = ft_puthex((int) va_arg(valist, int), 1);
	if (type == 'X')
		*len = ft_puthex((int) va_arg(valist, int), 2);
	if (type == '%')
		*len = ft_putchar('%');
}
