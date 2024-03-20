/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:01:41 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/20 16:39:19 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

/*
 * This function initialize the position and scale of the model
 * projected
 *
 * Scale->rotate->correct model->move->project
 */
void	initialize_mod(t_cor *cor, int col_i, int row_i)
{
	int factor;

	factor = (col_i * row_i);
	//move_model(cor, -col_i, 0, 1); // 100, 200, 1
	//scale_model(cor, 80, 80, 0.1);
	rotate_model(cor, 1, 0.2, 0.1); // 1, 0.7, 0.1
	move_model(cor, 0, 0, 5); // 100, 200, 1
	//scale_model(cor, 60, 60, 0.2);// 80 80 0.1 // 60, 60, 0.2
	project_model(cor);
	scale_projection(cor, 3, 3);
}
