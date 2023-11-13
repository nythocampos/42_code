/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_writer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:47:32 by antcampo          #+#    #+#             */
/*   Updated: 2023/10/26 15:33:06 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_nums(int num)
{
	int	count;

	count = 0;
	if (num == -2147483648)
		return (10);
	if (num == 0)
		return (1);
	if (num < 0)
		num = -num;
	while (num > 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

int	ft_putnbr(int n, int *len)
{
	unsigned int	num;

	num = (unsigned int) n;
	if (n < 0)
	{
		ft_putchar('-', len);
		num = -n;
	}
	if (num >= 10)
		ft_putnbr(num / 10, len);
	ft_putchar(num % 10 + '0', len);
	return (1);
}

int	ft_putunbr(unsigned int num, int *len)
{
	if (num >= 10)
		ft_putnbr(num / 10, len);
	ft_putchar(num % 10 + '0', len);
	return (-1);
}

int	ft_puthex(int num, char *hex, int *len)
{
	char	*to_write;
	char	num_size;
	int		index;

	index = 0;
	num_size = count_nums(num);
	to_write = (char *) malloc((num_size + 1) * (sizeof(char)));
	if (!to_write || !hex)
		return (-1);
	while (num != 0)
	{
		to_write[index] = hex[num % 16];
		num = num / 16;
		index++;
	}
	to_write[index] = '\0';
	//index += 1;
	while (index-- >= 0)
		ft_putchar(to_write[index], len);
	free(to_write);
	return (1);
}
