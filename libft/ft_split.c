/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:38:40 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/25 20:05:58 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_counter(const char *str, char c)
{
	size_t	cont1;
	size_t	cont2;

	cont1 = 0;
	cont2 = 0;
	while (str[cont1] != '\0')
	{
		if (str[cont1] != c && (str[cont1 + 1] == c || str[cont1 + 1] == '\0'))
			cont2++;
		cont1++;
	}
	return (cont2);
}

static char	**ft_free_split(char **str, size_t i)
{
	while (i > 0)
	{
		i--;
		free(str[i]);
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	cont1;
	int		cont2;

	str = malloc(sizeof(char *) * (ft_counter(s, c) + 1));
	if (!str)
		return (NULL);
	cont2 = -1;
	while (*s)
	{
		if (*s != c)
		{
			cont1 = 0;
			while (s[cont1] && s[cont1] != c)
				cont1++;
			str[++cont2] = ft_substr(s, 0, cont1);
			if (!str[cont2])
				return (ft_free_split(str, cont2));
			s += cont1;
		}
		else
			s++;
	}
	str[++cont2] = NULL;
	return (str);
}

/*
This function separates words contained in the char *s and
push them in its own memory spaces pointed by a new array.
*/
/*int	main(void)
{
	
	char const text[] = "hello!";
	char	**result;
	char	c = ' ';
	int		rows = get_array_size(text, c);
	int		i;
	int		len;
	int		start;

	start = find_pos(text, 0, &len, c);
	printf("source->%s\n", text);
	printf("rows->%d\n", rows);
	printf("start->%d\n", start);
	result = ft_split(text, c);
	printf("result->%s\n", result[0]);
	for (i=0; result[i] != 0; i++)
		printf("-->%s\n", result[i]);
	free(result);
	return (0);
}*/
//printf("index: %d ", index);
//printf("start:%d,next:%d,len:%d->%s\n", start, next_start, len, str[index]);
// if (index == (get_array_size(s, c)))
// 			str[index] = ft_calloc(1, sizeof(char));
// 		else
