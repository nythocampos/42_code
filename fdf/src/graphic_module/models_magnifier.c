/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models_magnifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:42:08 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/20 16:32:31 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	scale_model(t_cor *cor, float x, float y, float z)
{
	if (x != 0)
		cor->x = cor->x * x;
	if (y != 0)
		cor->y = cor->y * y;
	if (z != 0)
		cor->z = cor->z * z;
}

void	scale_projection(t_cor *cor, float x, float y)
{
	cor->x = cor->x * (x * WIDTH);
	cor->y = cor->y * (y * HEIGHT);
}
