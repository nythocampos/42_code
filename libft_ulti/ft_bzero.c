/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:52:19 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/16 13:52:24 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int		index;	
	char	*a;

	index = 0;
	a = (char *) s;
	while (n != 0)
	{
		a[index] = 0;
		index++;
		n--;
	}
}
