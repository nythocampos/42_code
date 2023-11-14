/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers_writer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:07:51 by antcampo          #+#    #+#             */
/*   Updated: 2023/11/14 10:12:03 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr, int *len)
{
	int	result;

	result = ft_putstr("0x", len);
	result *= ft_puthex((unsigned long long) ptr, "0123456789abcdef", len);
	if (result < 0)
		return (-1);
	return (1);
}
