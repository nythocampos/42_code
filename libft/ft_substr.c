/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:30:15 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/23 23:09:07 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		index;
	char	*str;

	index = 0;
	if (len >= ft_strlen(s))
		len = ft_strlen(s) - (size_t) start;
	if ((int) start > (int) ft_strlen(s) 
		|| (int) ft_strlen(s) == 0 || (int) start < 0 || (int) len < 0)
		return ((char *)ft_calloc(1, sizeof(char)));
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
This function returns a sub string from other string
int	main(void)
{
	char *result;

	result = ft_substr("hola", -1, -1);
	printf("result --->%s\n", result);
	printf("size: %ld\n", strlen(result));
	// if (len > ft_strlen(s))
	// 	len = ft_strlen(s) - (int) start;
	//str = (char *)ft_calloc(len + 1, sizeof(char));
	//str = (char *)malloc(len * sizeof(char) + 1);
	//printf("%u\n",start);
	//printf("%zu\n",len);
	return (0);
}*/
