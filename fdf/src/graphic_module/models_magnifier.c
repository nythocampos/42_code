/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models_magnifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:42:08 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/20 14:56:37 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	scale_model(t_cor *cor, float x, float y, float z)
{
	cor->x = cor->x * x;
	cor->y = cor->y * y;
	cor->z = cor->z * z;
}
