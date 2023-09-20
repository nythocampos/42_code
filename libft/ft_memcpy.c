/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:32:26 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/16 16:32:28 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	int		index;
	char	*a;

	index = 0;
	a = (char *) dst;
	if (dst == (void *) '\0' && src == (void *) '\0')
		return (dst);
	while (n != 0)
	{
		a[index] = *(char *)src;
		n--;
		index++;
		src++;
	}
	dst = a;
	return (dst);
}
