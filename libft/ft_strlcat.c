/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:14:38 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/20 10:14:40 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	int				dest_index;
	unsigned int	index;
	unsigned int	total_size;

	dest_index = ft_strlen(dst);
	index = 0;
	while (dstsize != 0)
	{
		dst[dest_index] = src[index];
		if (dstsize == 1)
			dst[dest_index] = '\0';
		index++;
		dest_index++;
		dstsize--;
	}
	total_size = dest_index;
	return (total_size);
}
/*
int	main(void)
{
	char	*dest;
	char	*src;
	int		dstsize;
	int     result;

	dest = "pqrstuvwxyz";
	src = "abcd";
	dstsize = 4;
	//ft_strlcat(dest, src, dstsize);
	result = strlcat(dest, src, dstsize);
	printf("dest: %s \n", dest);
	printf("result: %d \n", result);
	return (0);
}*/
