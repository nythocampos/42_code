/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:52:57 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/22 18:24:31 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*
int	main(void)
{
	char	s[] = "sadfvbf";
	//char	s[] = "";
	char	*result1;
	char	*result2;

	result1 = strdup(s);
	result2 = ft_strdup(s);
	printf("Real: %s \n", result1);
	printf("Fake: %s \n", result2);
	free(result1);
	free(result2);
}*/
