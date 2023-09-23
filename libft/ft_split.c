/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:38:40 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/24 01:43:59 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	find_pos(char const *s, int start, int *len, char c)
{
	int	index;

	index = start;
	*len = 0;
	while (s[index] != '\0')
	{
		if (s[index] == c)
			return (index - 1);
		*len = *len + 1;
		index++;
	}
	*len = index - 1;
	return (index - 1);
}

char	**ft_split(char const *s, char c)
{
	int		start;
	int		end;
	int		len;
	char	*str;

	start = 0;
	end = 0;
	while (start < ft_strlen(s))
	{
		end = find_pos(s, start, &len, c);
		printf("start: %d, end: %d, len: %d ", start, end, len);
		str = ft_substr(s, start, len);
		printf("--->%s\n", str);
		free(str);
		start = end + 2;
	}

	return ((char **) '\0');
}

int	main(void)
{
	char text[] = "perro cor tej";

	ft_split(text, ' ');
	return (0);
}
