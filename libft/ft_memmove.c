/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:15:54 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/18 09:15:56 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
This function copies len bytes from string src to string dst, 
but using a temporal buffer. This avoids the undefined behaviors.
*/
/*char	*create_temp_buffer(char *src, size_t size)
{
	int		index;	
	char	*temp;

	index = 0;
	temp = (char *) dst;
	while (src[index] != '\0')
	{
		temp[index] = src[index];
		index++;
	}
	return (temp);
}*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		index;
	char	*a;
	char	temp;

	index = 0;
	if ((dst == (void *) '\0' && src == (void *) '\0')
		|| (ft_strlen((char *)dst) < ft_strlen((char *)src)))
		return (dst);
	a = (char *) dst;
	while (len != 0)
	{
		temp = a[index];
		a[index] = *(char *)src;
		len--;
		index++;
		src++;
	}
	dst = a;
	return (dst);
}
