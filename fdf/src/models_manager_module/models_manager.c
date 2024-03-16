/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:01:41 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/16 02:19:02 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

/*
 * This function corrects the size
 * and position of the model
 *
 * Linux: x: 90, y: 90, z:0.1
 * Mac: x: ?, y: ?, z: ?
 */
static void	correct_mod(t_cor *cor)
{
	scale_model(cor, 90, 90, 0.1);
	move_model(cor, 0, 0, 0);
}

void	initialize_mod(t_cor *cor)
{
	scale_model(cor, 1, 0.2, 1);
	rotate_model(cor,1, 0.7, 0.1);
	correct_mod(cor);
	move_model(cor, 100, 200, 1);
	project_model(cor);
}
