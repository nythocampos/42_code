/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:09:10 by antcampo          #+#    #+#             */
/*   Updated: 2023/10/04 14:26:18 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 
#include "libftprintf.h"

void	select_writer(char type, va_list valist, int *len)
{
	if (type == 'c')
		putchar(va_arg(valist));
	if (type == 's')
	if (type == 'p')
	if (type == 'i')
	if (type == 'u')
	if (type == 'x')
	if (type == 'X')
	if (type == '%')
}
