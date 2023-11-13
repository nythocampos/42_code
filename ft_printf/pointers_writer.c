/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers_writer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:07:51 by antcampo          #+#    #+#             */
/*   Updated: 2023/10/26 15:32:57 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putptrhex(unsigned long int num, int *len)
{
	char	*to_write;
	char	*hex;
	char	num_size;
	int		index;

	hex = "0123456789abcdef";
	index = 1;
	num_size = count_nums(num);
	to_write = (char *) malloc(num_size * (sizeof(char) + 1));
	while (num != 0)
	{
		to_write[index] = hex[num % 16];
		num = num / 16;
		index++;
	}
	to_write[index] = '\0';
	while (index-- >= 0)
		ft_putchar(to_write[index], len);
	free(to_write);
	return (num_size);
}

int	ft_putptr(void *ptr, int *len)
{
	int		result_size;

	result_size = 0;
	result_size += ft_putstr("0x", len);
	result_size += putptrhex((unsigned long int) ptr, len);
	return (result_size + 2);
}
