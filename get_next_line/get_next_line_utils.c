/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:56:55 by antcampo          #+#    #+#             */
/*   Updated: 2023/11/03 19:57:04 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **buffer)
{
	free(*buffer);
	buffer = NULL;
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	char	to_find;

	to_find = (char) c;
	while (1)
	{
		if ((*s == to_find) || (*s == '\0' && to_find == '\0'))
			return ((char *)s);
		if (*s == '\0')
			break ;
		s++;
	}
	return ((char *) '\0');
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		index;
	char	*a;

	index = 0;
	a = (char *) dst;
	if (dst == (void *) '\0' && src == (void *) '\0')
		return (dst);
	while (n != 0)
	{
		a[index] = *(char *)src;
		n--;
		index++;
		src++;
	}
	dst = a;
	return (dst);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		index;

	str = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (str == 0)
		return (0);
	index = 0;
	while (s[index] != '\0')
	{
		str[index] = s[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}

char	*mod_strjoin(char const *s1, char const *s2)
{
	size_t	str_size;
	char	*str;
	int		index;

	if (s2 == 0)
		return (NULL);
	index = -1;
	str_size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((str_size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (index++ < (int) ft_strlen(s1))
		str[index] = s1[index];
	index = -1;
	while (index++ < (int) ft_strlen(s2))
		str[ft_strlen(s1) + index] = s2[index];
	free((char *)(s1));
	return (str);
}
