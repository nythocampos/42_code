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
	if (index == 0 && s[0] != c)
		return (0);
	while (1)
	{
		if (s[index - 1] == c && (s[index] != c))
			return (index);
		if (s[index] != c)
			*len = *len + 1;
		if (index >= ft_strlen(s))
			break ;
		index++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		index;
	int		start;
	int		next_start;
	int		len;
	char	**str;

	index = 0;
	start = find_pos(s, index, &len, c);
	str = (char **)ft_calloc(1, sizeof(char *));
	if (ft_strlen(s) == 0 || start >= ft_strlen(s))
		return (str);
	free(str);
	str = (char **)ft_calloc(get_array_size(s, c), sizeof(char *) + 8);
	if (str == 0)
		return (0);
	while (index < get_array_size(s, c))
	{
		next_start = find_pos(s, start + 1, &len, c);
		str[index] = ft_substr(s, start, len + 1);
		start = next_start;
		index++;
	}
	return (str);
}

/*int	main(void)
{
	
	printf("rows: %d, sizeof: %zu\n", get_array_size(s, c), sizeof(char *));
	char const text[] = "--1-2--3---4----5-----42";
	char	**result;
	char	c = '-';
	int		rows = get_array_size(text, c);
	int		i;
	int		len;
	int		start;

	start = find_pos(text, 0, &len, c);
	printf("source->%s\n", text);
	printf("rows->%d\n", rows);
	printf("start->%d\n", start);
	result = ft_split(text, c);
	printf("result->%s\n", result[5]);
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
