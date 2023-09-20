/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:46:35 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/15 16:46:37 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				index;
	unsigned char	*a;

	index = 0;
	a = (unsigned char *)b;
	while (index < len)
	{
		a[index] = (unsigned char)c;
		index++;
	}
	return (b);
}
