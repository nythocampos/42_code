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
	t_cor	scl;
	t_cor	n_pos;

	scl.x = 90; // linux 90 // mac
	scl.y = 90; // 90
	scl.z = 0.1; //0.1
	magnify_model(model_data, &scl);
	n_pos.x = 0;
	n_pos.y = 0;
	n_pos.z = 0;
	move_model(model_data, &n_pos, 1);
}

void	initialize_mod(t_list *model_data, int model_num)
{
	t_cor	angles;
	t_cor	scl;
	t_cor	n_pos;

	//remove model_num
	ft_printf("model_num: %d\n", model_num);
	scl.x = 1;
	scl.y = 0.2;
	scl.z = 1;
	magnify_model(model_data, &scl);
	angles.x = 1;
	angles.y = 0.7;
	angles.z = 0.1;
	rotate_model(model_data, &angles);
	correct_mod(model_data);
	n_pos.x = 100;
	n_pos.y = 200;
	n_pos.z = 1;
	move_model(model_data, &n_pos, 1);
	project_model(model_data);
}
