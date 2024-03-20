/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models_positioner.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:48:07 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/20 14:53:30 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

/*
 * This function move the model to the new position
 * adding up to its axes.
 * Args:
 * 	model ():
 * 	n_pos (void *): values to add
 */
void	move_model(t_cor *cor, float x, float y, float z)
{
	cor->x = cor->x + x;
	cor->y = cor->y + y;
	cor->z = cor->z + z;
}

