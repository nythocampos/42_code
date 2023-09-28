/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:49:29 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/19 12:49:32 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	index;

	index = 0;
	while (n != 0)
	{
		if (s1[index] == '\0' || s2[index] == '\0')
		{
			if (ft_strlen(s1) > ft_strlen(s2))
				return (1);
			else if (ft_strlen(s1) < ft_strlen(s2))
				return (-1);
			else if (ft_strlen(s1) == ft_strlen(s2))
				return (0);
		}
		if (s1[index] != s2[index])
			return ((unsigned char) s1[index] - (unsigned char) s2[index]);
		index++;
		n--;
	}
	return (0);
}
