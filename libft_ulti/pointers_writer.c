/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers_writer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:07:51 by antcampo          #+#    #+#             */
/*   Updated: 2023/11/17 08:04:17 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr(unsigned long long ptr, int *len)
{
	ft_putstr("0x", len);
	if (*len == -1)
		return ;
	ft_puthex(ptr, "0123456789abcdef", len);
}
