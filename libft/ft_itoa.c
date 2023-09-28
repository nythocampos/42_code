/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:52:31 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/28 03:46:34 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

int	count_nums(int num)
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

void	to_string(unsigned int num, int *index, char *str)
{
	if (num >= 10)
		to_string(num / 10, index, str);
	str[*index] = (num % 10 + '0');
	*index = *index + 1;
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	int				index;
	int				size;
	char			*str;

	index = 0;
	if (n < 0)
		str = (char *)malloc((sizeof(char) + 8) * ((count_nums(num) + 1) + 1));
	else
		str = (char *)malloc((sizeof(char) + 8) * (count_nums(num) + 1));
	if (str == 0)
		return (0);
	num = n;
	if (n < 0)
	{
		str[0] = '-';
		num = -n;
		index = index + 1;
	}
	to_string(num, &index, str);
	str[index] = '\0';
	return (str);
}

/*
if (n < 0)
		size = count_numbers(num) + 1;
	else
		size = count_numbers(num);
	str = (char *)malloc(sizeof(char) * (size + 1));
*/
/*int	main(void)
{
	printf("count: %d\n", count_nums(1000034));
	printf("Test 0.ft_itoa->%s, Expected:%s\n", ft_itoa(-9), "-9");
	printf("Test 1.ft_itoa->%s, Expected:%s\n", ft_itoa(-10), "-10");
	printf("Test 2.ft_itoa->%s, Expected:%s\n", ft_itoa(543000), "543000");
	printf("Test 3.ft_itoa->%s\n", ft_itoa(-2147483648));
	return (0);
}*/
