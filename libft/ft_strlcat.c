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

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	int				dest_size;
	unsigned int	index;
	unsigned int	total_size;

	dest_size = ft_strlen(dst);
	index = 0;
	while ((src[index] != '\0') && (index < dstsize))
	{
		dst[dest_size] = src[index];
		index++;
		dest_size++;
	}
	dst[dest_size] = '\0';
	total_size = ft_strlen(dst);
	return (total_size);
}
