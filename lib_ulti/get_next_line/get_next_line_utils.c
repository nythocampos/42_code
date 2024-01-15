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
	*buffer = NULL;
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
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

char	*ft_strdup(const char *s)
{
	char	*str;
	int		index;

	str = (char *)malloc((ft_strlen(s)+ 1) * sizeof(char));
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

char	*mod_strjoin(char *s1, char const *s2)
{
	char	*str;
	int		index;
	int		len1;
	int		len2;

	if (s2 == 0)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *) malloc((len1 + len2) + 1 * sizeof(char));
	if (str == 0)
		return (ft_free(&s1));
	index = -1;
	while (index++ < len1)
		str[index] = s1[index];
	index = -1;
	while (index++ < len2)
		str[len1 + index] = s2[index];
	str[len1 + index - 1] = '\0';
	ft_free(&s1);
	return (str);
}
