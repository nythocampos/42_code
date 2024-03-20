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
	cor->x = cor->x * x;
	cor->y = cor->y * y;
	cor->z = cor->z * z;
}

void	scale_projection(t_cor *cor, float x, float y)
{
	cor->x = cor->x * (x * WIDTH);
	cor->y = cor->y * (y * HEIGHT);
}
