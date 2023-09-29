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
	int		index;
	char	*str;

	index = 0;
	if ((int)len >= (int)ft_strlen(s) || (int) len < 0)
		len = (size_t)(ft_strlen(s) - (int) start);
	if ((int) start > (int) ft_strlen(s) || (int) ft_strlen(s) == 0
		|| (int) start < 0 || (int) len == 0)
		return ((char *)ft_calloc(1, sizeof(char)));
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (str == 0)
		return (0);
	while (s[start + index] != '\0' && (int)len > index)
	{
		str[index] = s[start + index];
		index++;
	}
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
	char			*result;
	unsigned int	start = 0;
	size_t			len = -1;

	if ((int)len < 0)
		printf("negative\n");

	printf("Fake--->%s\n", ft_substr("hola", start, len));
	printf("Real--->%s\n", ft_substr("hola", start, len));
	return (0);
}*/