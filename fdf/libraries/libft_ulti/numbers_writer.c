/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_writer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:47:32 by antcampo          #+#    #+#             */
/*   Updated: 2023/11/17 08:09:23 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_nums(unsigned long long num)
{
	int	count;

	count = 0;
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

void	ft_putnbr(int n, int *len)
{
	unsigned int	num;

	num = (unsigned int) n;
	if (n < 0)
	{
		ft_putchar('-', len);
		if (*len == -1)
			return ;
		num = -n;
	}
	if (num >= 10)
		ft_putnbr(num / 10, len);
	if (*len == -1)
		return ;
	ft_putchar(num % 10 + '0', len);
}

void	ft_putunbr(unsigned int num, int *len)
{
	if (num >= 10)
		ft_putnbr((num / 10), len);
	if (*len == -1)
		return ;
	ft_putchar((num % 10 + '0'), len);
}

static void	write_hex(int index, char *to_write, int *len)
{
	while (index-- > 0)
	{
		ft_putchar(to_write[index], len);
		if (*len == -1)
			return ;
	}
}

void	ft_puthex(unsigned long long num, char *hex, int *len)
{
	char	*to_write;
	int		index;

	index = 0;
	if (num == 0)
	{
		ft_putchar('0', len);
		return ;
	}
	to_write = (char *) malloc((count_nums(num) + 1) * (sizeof(char)));
	if (!to_write)
	{
		*len = -1;
		return ;
	}
	while (num != 0)
	{
		to_write[index] = hex[num % 16];
		num = num / 16;
		index++;
	}
	to_write[index] = '\0';
	write_hex(index, to_write, len);
	free(to_write);
}
