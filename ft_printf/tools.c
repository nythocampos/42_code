/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:09:10 by antcampo          #+#    #+#             */
/*   Updated: 2023/10/05 18:12:07 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
		ft_putchar_fd((char) va_arg(valist, int), 1);
	if (type == 's')
		ft_putstr_fd((char *) va_arg(valist, char *), 1);
	//if (type == 'p')
	//	ft_putchar_fd((void *) va_arg(valist, void *), 1);
	if (type == 'd')
		ft_putnbr_fd((int) va_arg(valist, int), 1);
	if (type == 'i')
		ft_putnbr_fd((int) va_arg(valist, int), 1);
	if (type == 'u')
		ft_putnbr_fd((int) va_arg(valist, int), 1);
	if (type == 'x')
		ft_puthex((int) va_arg(valist, int), 1);
	if (type == 'X')
		ft_puthex((int) va_arg(valist, int), 2);
	if (type == '%')
		ft_putchar_fd('%', 1);
}
