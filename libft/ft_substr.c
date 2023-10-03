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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;

	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len >= ft_strlen(s + start) || len < 0)
		len = (ft_strlen(s + start));
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	ft_memcpy(result, s + start, len);
	result[len] = '\0';
	return (result);
}

/*
str = (char *)ft_calloc(len + 1, sizeof(char));
str = (char *)malloc(len * sizeof(char));
printf("start: %d, index: %d, len: %d\n", start, index, (int)len);
This function returns a sub string from other string

If len is greater than s size, then assign to len the 
total size from start onwards
*/
/*int	main(void)
{
	//char			*result;
	//unsigned int	start = 0;
	//size_t			len = -1;

	//if ((int)len < 0)
	//	printf("negative\n");

	printf("\"%s\"\n", ft_substr("hola", 2, 9));
	//printf("Real--->%s\n", ft_substr("hola", start, len));
	return (0);
}*/