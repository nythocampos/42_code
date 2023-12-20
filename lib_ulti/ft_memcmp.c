/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:35:38 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/21 19:36:08 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	int				index;

	index = 0;
	a = (unsigned char *) s1;
	b = (unsigned char *) s2;
	while (n != 0)
	{
		if (a[index] != b[index])
			return (a[index] - b[index]);
		index++;
		n--;
	}
	return (0);
}
