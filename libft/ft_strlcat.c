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
	int				dst_len;
	int				src_len;
	size_t			index;
	int				dest_first_size;

	dst_len = ft_strlen(dst);
	dest_first_size = dst_len;
	src_len = ft_strlen(src);
	index = 0;
	if (dstsize < (size_t)dst_len)
		return (src_len + (int) dstsize);
	while ((src[index] != '\0') && ((size_t)(dst_len + 1) < dstsize))
	{
		dst[dst_len] = src[index];
		index++;
		dst_len++;
	}
	dst[dst_len] = '\0';
	return (dest_first_size + src_len);
}

/*int	main(void)
{
	//char	dest[20] =  "a";
	char	dest[20] =  "pqrs";
	char	*src;
	int		dstsize;
	int		result;

	//src = "lorem ipsum dolor sit amet";
	src = "abcdefghi";
	dstsize = 13;
	result = ft_strlcat(dest, src, dstsize);
	//result = strlcat(dest, src, dstsize);
	printf("dest result: %s \n", dest);
	printf("total string lenght: %d \n", result);
	return (0);
}*/
