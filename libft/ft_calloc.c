/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:54:56 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/22 17:47:49 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*result;
	int		index;

	index = 0;
	result = (char *)malloc(nmemb * size);
	if (!result)
		return (0);
	while (index <= (int)(nmemb * size))
	{
		result[index] = 0;
		index++;
	}
	return ((void *)result);
}
/*
int	main(void)
{
	size_t	nmemb = 0;
	size_t	size = 0;

	printf("Real function: %s \n", (char *) calloc(nmemb, size));
	printf("Fake function: %s \n", (char *)ft_calloc(nmemb, size));
	return (0);
}*/
