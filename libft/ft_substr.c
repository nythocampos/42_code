/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:30:15 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/22 22:05:19 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		index;
	char	*str;

	str = (char *)ft_calloc(3, sizeof(char));
	index = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s) - (size_t) start;
	if ((int) start > (int) ft_strlen(s) 
		|| (int) ft_strlen(s) == 0)
		return (str);
	free(str);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (str == 0)
		return (0);
	while (len > 0 && s[start] != '\0')
	{
		str[index] = s[start];
		start++;
		index++;
		len--;
	}
	return (str);
}
/*
int	main(void)
{
	char text[] = "lorem ipsum dolor sit amet";
	size_t max = 18446744073709;
	char *result;

	result = ft_substr("tripouille", 1, 1);
	printf("result --->%s\n", result);
	printf("size: %ld\n", strlen(result));
	printf("size: %ld\n", strlen(result));
	if (ft_strlen(result) == 2)
		printf("OK\n");
	// if (len > ft_strlen(s))
	// 	len = ft_strlen(s) - (int) start;
	//str = (char *)ft_calloc(len + 1, sizeof(char));
	//str = (char *)malloc(len * sizeof(char) + 1);
	return (0);
}*/
