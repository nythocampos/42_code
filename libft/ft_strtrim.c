/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:15:24 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/23 22:37:20 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	find_substr(char *s1, char *set, int *l_pos, int *r_pos)
{
	int	index;

	index = 0;
	while (s1[index] != '\0')
	{
		if (ft_strchr(set, s1[index]) == ((char *) '\0'))
		{
			*l_pos = index;
			break ;
		}
		index++;
	}
	index = ft_strlen(s1) - 1;
	while (index >= 0)
	{
		if (ft_strchr(set, s1[index]) == ((char *) '\0'))
		{
			*r_pos = index + 1;
			return (1);
		}
		index--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int			l_pos;
	int			r_pos;
	int			res_find_sub;
	char		*str;

	l_pos = 0;
	r_pos = ft_strlen(s1);
	str = (char *)ft_calloc(1, sizeof(char));
	res_find_sub = find_substr((char *) s1, (char *) set, &l_pos, &r_pos);
	if (ft_strlen(s1) <= 0 || res_find_sub == 0)
		return (str);
	free(str);
	if (str == 0)
		return (0);
	str = ft_substr(s1, l_pos, (r_pos - l_pos));
	return (str);
}
/*
Find a sub string contained between characteres
int	main(void)
{
	char	set[] = "+-/?";

	printf("Test: 0-->%s\n", ft_strtrim("ab cd  f   ", " "));
	printf("Test: 1-->%s\n", ft_strtrim("lorem ipsum dolor sit amet", "te"));
	printf("Test: 2-->%s\n", 
		ft_strtrim("xxxz  test with x and z and x .  zx  xx z", "z x"));
}*/
