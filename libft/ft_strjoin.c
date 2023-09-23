/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:28:01 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/23 22:49:32 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			index;
	size_t		str_size;
	char		*str;

	index = 0;
	if ((ft_strlen(s1) <= 0 && ft_strlen(s2) <= 0))
		return ((char *)ft_calloc(1, sizeof(char)));
	str_size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)ft_calloc(str_size + 1, sizeof(char));
	if (str == 0)
		return (0);
	if (s1[0] != 0)
		ft_memcpy(str, (const char *)s1, ft_strlen(s1));
	if (s2[0] != 0)
		ft_memcpy(&str[ft_strlen(s1)], (const char *)s2, ft_strlen(s2));
	return (str);
}
/*
Concat 2 strings
int	main(void)
{
	printf("%zu\n", ft_strlen(""));
	printf("Test: 0-->%s\n", ft_strjoin("perro ", "corriendo"));
	printf("Test: 1-->%s\n", ft_strjoin(" ", "corriendo"));
	printf("Test: 2-->%s\n", ft_strjoin(" ", " "));
	printf("Test: 3-->%s\n", ft_strjoin("", " "));
	printf("Test: 4-->%s\n", ft_strjoin(" ", ""));
	printf("Test: 5-->%s\n", ft_strjoin("", ""));
	printf("Test: 6-->%s\n", ft_strjoin("", " hello"));
}*/
