/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:52:31 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/27 15:56:21 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

char	*reverse_string(char str[], int length)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = length - 1;
	while (start < end) 
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return (str);
}

int	count_numbers(int num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1); 
	if (num < 0)
		num = -num;
	while (num > 0) 
	{
		num /= 10;
		count++;
	}
	return (count);
}

void	to_string(int n, int index, char *str)
{
	int		is_negative;

	index = 0;
	is_negative = 0;
	if (n == 0)
		str[index++] = '0';
	else if (n < 0) 
	{
		is_negative = 1;
		n = -n;
	}
	while (n > 0) 
	{
		str[index++] = n % 10 + '0';
		n /= 10;
	}
	if (is_negative) 
		str[index++] = '-';
	str[index] = '\0';
	str = reverse_string(str, index);
}

char	*ft_itoa(int n)
{
	char	*str;

	str = (char *)ft_calloc(count_numbers(n) + 1, sizeof(char) + 8);
	if (str == 0)
		return (0);
	to_string(n, 0, str);
	return (str);
}

/*int	main(void)
{
	printf("Test 0.ft_itoa->%s, Expected:%s\n", ft_itoa(-9), "-9");
	printf("Test 1.ft_itoa->%s, Expected:%s\n", ft_itoa(-10), "0");
	printf("Test 2.ft_itoa->%s, Expected:%s\n", ft_itoa(-9874), "-9874");
	printf("Test 3.ft_itoa->%s", ft_itoa(-2147483648));
	return (0);
}*/