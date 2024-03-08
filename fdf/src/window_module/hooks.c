/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:01:05 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/08 13:15:40 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

/*
 * This function close the program and free al
 * memory used
 */
void	end_program(t_state *state)
{
	t_mlx_data	*mlx_data;

	mlx_data = state->mlx_data;
	mlx_destroy_window(mlx_data->mlx, mlx_data->win);
	mlx_destroy_image(mlx_data->mlx, mlx_data->img->img);
	free(mlx_data->mlx);
	exit(1);
}

/*
This function moves the model selected

TODO: add a way to apply the changes on the selected
model

TODO: update this name to move_model
: add move up and move down
*/
void	update_m_pos(t_state *state, int key)
{
	t_list	*model;
	int		increment;
	t_cor	n_pos;

	increment = 1;
	model = state->models[0].model_data;
	n_pos.x = 0;
	n_pos.y = 0;
	n_pos.z = 0;
	if (key == 'w')
	{
		n_pos.z = increment;
		move_model(model, n_pos);
		ft_printf("move to forward\n");
	}
	else if (key == 's'){
		n_pos.z = increment;
		move_model(model, n_pos);
		move_model(0, 0, -increment);
		ft_printf("move to backward\n");
	}
	else if (key == 'a'){
		n_pos.x = -increment;
		move_model(model, n_pos);
		ft_printf("move to left\n");
	}
	else if (key == 'd'){
		n_pos.x = increment;
		move_model(model, 0, 0);
		ft_printf("move to right\n");
	}
}

/*
This function updates the model scale

*/
void	scale_model(t_state *state, int key)
{
	int		increment;
	t_cor	n_pos;
	t_list	*model;

	increment = 1;	
	model = state->models[0].model_data;
	if (key == '+')
	{
		scl.x = increment;
		scl.y = increment * 0.2;
		scl.z = increment;
		magnify_model(model_data, &scl);
		ft_printf("scale +\n");
	}
	else if (key == '-')
	{
		scl.x = -increment;
		scl.y = -increment * 0.2;
		scl.z = -increment;
		magnify_model(model_data, &scl);
		ft_printf("scale +\n");
	}
}
void	update_r_pos(t_state *state, int key)
{
	t_list	*model;
	int		increment;
	t_cor	n_ang;

	increment = 0.5;
	model = state->models[0].model_data;
	n_ang.x = 0;
	n_ang.y = 0;
	n_ang.z = 0;
	if (key == 'i')
	{
		n_ang.x = increment;
		scale_model(model, n_pos);
		ft_printf("rotate to forward\n");
	}
	else if (key == 'k'){
		n_ang.x = increment;
		scale_model(model, n_pos);
		ft_printf("rotate to backward\n");
	}
	else if (key == 'j'){
		n_ang.z = -increment;
		scale_model(model, n_pos);
		ft_printf("rotate to left\n");
	}
	else if (key == 'l'){
		n_ang.z = increment;
		scale_model(model, n_ang);
		ft_printf("rotate to right\n");
	}
}
