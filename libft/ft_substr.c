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
	int		size;

	index = 0;
	size = (int) len;
	if ((int) start > (int) ft_strlen(s) || (int) ft_strlen(s) == 0
		|| (int) start < 0 || size == 0)
		return ((char *)ft_calloc(1, sizeof(char)));
	if (size >= (int)ft_strlen(s + start) || size < 0)
		size = ((int)ft_strlen(s + start));
	str = (char *)malloc((size + 1) * sizeof(char));
	if (str == 0)
		return (0);
	while (s[start + index] != '\0' && size > index)
	{
		str[index] = s[start + index];
		index++;
	}
	str[index] = '\0';
	return (str);
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