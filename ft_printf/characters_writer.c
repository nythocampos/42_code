/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters_writer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:47:24 by antcampo          #+#    #+#             */
/*   Updated: 2023/10/26 15:03:47 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char c)
{
	if (c == '\0')
		return (-1);
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	if (s == 0)
		return (-1);
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}
