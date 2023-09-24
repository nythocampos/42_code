/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:38:40 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/24 03:10:55 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	get_array_size(char const *s, char c)
{
	int	index;
	int	rows;

	index = 1;
	rows = 0;
	while (1)
	{
		if ((s[index] == c || s[index] == '\0') 
			&& (s[index - 1] != c))
			rows++;
		if (s[index] == '\0')
			break ;
		index++;
	}
	return (rows);
}

static int	find_pos(char const *s, int start, int *len, char c)
{
	int	index;

	index = start;
	*len = 0;
	while (s[index] != '\0')
	{
		if (s[index] == c && (s[index - 1] != c))
			return (index - 1);
		*len = *len + 1;
		index++;
	}
	*len = index - 1;
	return (index - 1);
}

char	*get_substr(char const *s, char c)
{
	int		start;
	int		end;
	int		len;
	char	*str;

	while (start < ft_strlen(s))
	{
		end = find_pos(s, start, &len, c);
		printf("start: %d, end: %d, len: %d ", start, end, len);
		str = ft_substr(s, start, len);
		printf("--->%s\n", str);
		free(str);
		start = end + 2;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		index;
	int		start;
	int		end;
	int		len;
	char	**str;

	index = 0;
	start = 0;
	end = 0;
	if (ft_strlen(s) == 0 || c == '\0')
		return ((char **)ft_calloc(1, sizeof(char)));
	str = (char **)ft_calloc(get_array_size(s, c), sizeof(char *));
	while (start < ft_strlen(s) && index <= get_array_size(s, c))
	{
		end = find_pos(s, start, &len, c);
		printf("start: %d, end: %d, len: %d ", start, end, len);
		str[index] = ft_substr(s, start, len);
		printf("--->%s\n", str[index]);
		start = end + 2;
		index++;
	}
	printf(" ----- \n");
	return (str);
}

int	main(void)
{
	//char const text[] = "perro cor tej";
	char const text[] = "perro cor tej    asd";
	char	**result;
	char	c = ' ';
	int		rows = get_array_size(text, c);
	int		i;
	int		j;

	//get_substr(text, c);
	result = ft_split(text, c);
	for (i=0; i<rows; i++)
		printf("-->%s\n", result[i]);
	//printf("%d \n", get_array_size(text, c));
	free(result);
	return (0);
}
