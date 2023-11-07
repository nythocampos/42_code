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

int	mod_strchr(char *s, char c)
{
	int	index;

	index = 0;
	if (s == 0)
		return (-1);
	while (s[index] != '\0')
	{
		if (s[index] == c)
			return (1);
		index++;
	}
	return (0);
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
	char	*str;
	int		index;
	int 	len1;
	int 	len2;

	if (s2 == 0)
		return (NULL);
	index = -1;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (index++ < len1)
		str[index] = s1[index];
	index = -1;
	while (index++ < len2)
		str[len1 + index] = s2[index];
	free((char *)(s1));
	return (str);
}
