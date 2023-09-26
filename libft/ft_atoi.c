/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:23:07 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/22 16:51:48 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *nptr)
{
	int	index;
	int	result;
	int	is_negative;

	index = 0;
	result = 0;
	is_negative = 0;
	while (nptr[index] == ' ' || nptr[index] == '\f' || nptr[index] == '\n'
		|| nptr[index] == '\r' || nptr[index] == '\t' || nptr[index] == '\v')
		index++;
	if (nptr[index] == '-' || nptr[index] == '+')
	{
		if (nptr[index] == '-')
			is_negative = 1;
		index++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		result *= 10;
		result += nptr[index] - '0';
		index++;
	}
	if (is_negative == 1)
		result *= -1;
	return (result);
}
/*
int	main()
{
	char example1[] = "\n\n\n  -46\b9 \n5d6";
	char example[] = "\n\n\n  -46\b9 \n5d6";

	printf("Real function: %d \n", atoi(example1));
	printf("Fake function: %d \n", ft_atoi(example));
	return (0);
}*/