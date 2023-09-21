/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:54:44 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/21 18:18:07 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int				dst_len;
	int				src_len;
	size_t			index;

	dst_len = 0;
	index = 0;
	src_len = ft_strlen(src);
	if (size <= 0)
		return (src_len);
	while ((src[index] != '\0') && (index < size - 1))
	{
		dst[dst_len] = src[index];
		index++;
		dst_len++;
	}
	dst[dst_len] = '\0';
	return (src_len);
}
/*
int	main(void)
{
	char	dest[20] =  "";
	char	src[20] = "tests";
	int		size;
	int		result;

	size = 6;
	result = ft_strlcat(dest, src, size);
	printf("dest result: %s \n", dest);
	printf("total string lenght: %d \n", result);
	return (0);
}*/