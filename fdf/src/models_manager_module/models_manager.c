/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:01:41 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/15 21:05:32 by antcampo         ###   ########.fr       */
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
static void	correct_mod(t_list *model_data)
{
	magnify_model(model_data, 50, 50, 0.1);
	move_model(model_data, 0, 0, 0);
}

void	initialize_mod(t_list *model_data)
{
	magnify_model(model_data, 1, 0.1, 0.8);
	rotate_model(model_data, 1.1, 0.2, 0.1);
	correct_mod(model_data);
	move_model(model_data, 100, 200, 1);
	project_model(model_data);
}
