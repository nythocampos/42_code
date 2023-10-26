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

int	ft_putnbr(int n)
{
	unsigned int	num;
	int				num_size;

	num = (unsigned int) n;
	num_size = count_nums(num);
	if (n < 0)
	{
		ft_putchar('-');
		num = -n;
	}
	if (num >= 10)
		ft_putnbr(num / 10);
	ft_putchar(num % 10 + '0');
	return (num_size);
}

int	ft_putunbr(unsigned int num)
{
	int	num_size;

	num_size = count_nums(num);
	if (num >= 10)
		ft_putnbr(num / 10);
	ft_putchar(num % 10 + '0');
	return (num_size);
}

int	ft_puthex(int num, int mode)
{
	char	*to_write;
	char	*hex;
	char	num_size;
	int		index;

	if (mode == 1)
		hex = "0123456789abcdef";
	else if (mode == 2)
		hex = "0123456789ABCDEF";
	index = 0;
	num_size = count_nums(num);
	to_write = (char *) malloc((sizeof(char) + 1) * num_size);
	while (num != 0)
	{
		to_write[index] = hex[num % 16];
		num = num / 16;
		index++;
	}
	to_write[index] = '\0';
	while (index-- >= 0)
		ft_putchar(to_write[index]);
	free(to_write);
	return (num_size);
}
