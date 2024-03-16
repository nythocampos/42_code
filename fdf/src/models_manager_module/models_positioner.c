/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models_positioner.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:48:07 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/05 13:48:20 by antcampo         ###   ########.fr       */
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
static void	move_to_pos(t_cor *cor, void *n_pos)
{
	t_cor	*new_p;

	new_p = (t_cor *) n_pos;
	cor->x = cor->x + new_p->x;
	cor->y = cor->y + new_p->y;
	cor->z = cor->z + new_p->z;
}

/*
 * This function moves the object to a new position.
 *
 * Args:
 * 	mode (t_face): the model to be moved.
 * 	n_pos(t_cor): new position where the model must be
 * 	pleaced.
 */
void	move_model(t_list *model, float x, float y, float z)
{	
	t_cor	n_pos;

	n_pos.x = x;
	n_pos.y = y;
	n_pos.z = z;
	process_lists(model, (void *) &n_pos, move_to_pos);
}
