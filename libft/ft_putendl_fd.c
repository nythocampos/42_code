/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:31:04 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/27 18:32:43 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s != 0)
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}

/*int	main(void)
{
	ft_putendl_fd(NULL, 1);
	ft_putendl_fd("TEST", 1);
	return (0);
}*/