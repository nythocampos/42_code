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
 * This function teleport the object to the
 * position specified
 *
 * Args:
 * 	model ()
 * 	n_pos (void): new position
 */
static void	apply_position(t_cor *cor, void *n_pos)
{
	t_cor	*new_p;

	new_p = (t_cor *) n_pos;
	cor->x = new_p->x;
	cor->y = new_p->y;
	cor->z = new_p->z;
}

/*
 * This function moves the object to a new position.
 *
 * Args:
 * 	mode (t_face): the model to be moved.
 * 	n_pos(t_cor): new position where the model must be
 * 	pleaced.
 */
void	move_model(t_list *model, t_cor *n_pos, int mov_ty)
{
	if (mov_ty == 0)
		process_lists(model, (void *) n_pos, apply_position);
	else if (mov_ty == 1)
		process_lists(model, (void *) n_pos, move_to_pos);
}
