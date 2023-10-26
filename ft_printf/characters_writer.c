/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters_writer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:47:24 by antcampo          #+#    #+#             */
/*   Updated: 2023/10/26 12:25:16 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	if (s != 0)
		write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}
