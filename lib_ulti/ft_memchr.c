/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:20:22 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/21 18:31:32 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*a;

	a = (unsigned char *) s;
	while (n != 0)
	{
		if (*a == (unsigned char) c)
			return (a);
		a++;
		n--;
	}
	return (0);
}
