/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:04:02 by antcampo          #+#    #+#             */
/*   Updated: 2023/11/17 08:28:08 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(char const *args, ...)
{
	int		index;
	int		total_len;
	va_list	valist;

	index = 0;
	total_len = 0;
	va_start(valist, args);
	while (args[index] != '\0')
	{
		if (args[index] != '%')
			ft_putchar(args[index], &total_len);
		else if (args[index] == '%')
		{
			if (args[index + 1] == '\0')
				return (total_len);
			select_writer(args[index + 1], valist, &total_len);
			index++;
		}
		if (total_len == -1)
			return (-1);
		index++;
	}
	va_end(valist);
	return (total_len);
}
