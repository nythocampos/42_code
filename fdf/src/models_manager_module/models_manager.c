/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:01:41 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/16 04:06:16 by antcampo         ###   ########.fr       */
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
static void	correct_pos(t_cor *cor, int col_i, int row_i)
{
	int factor;

	factor = (col_i * row_i);
	scale_model(cor, 60, 60, 0.2);// 80 80 0.1 // 60, 60, 0.2
	move_model(cor, -col_i, 0, -row_i*0.01);
}

/*
 * This function initialize the position and scale of the model
 * projected
 *
 * Scale->rotate->correct model->move->project
 */
void	initialize_mod(t_cor *cor, int col_i, int row_i)
{
	//move_model(cor, -col_i, 0, 1); // 100, 200, 1
	scale_model(cor, 1, 0.2, 0.8);
	rotate_model(cor, 1, 0.2, 0.1); // 1, 0.7, 0.1
	correct_pos(cor, col_i, row_i);
	move_model(cor, 0, 0, 1); // 100, 200, 1
	project_model(cor);
	return ;
	ft_printf("%d %d\n", col_i, row_i);
}
