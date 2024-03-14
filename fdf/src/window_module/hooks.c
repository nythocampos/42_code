/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:01:05 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/14 21:27:38 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static void	del(void *content)
{
	free(content);
	content = NULL;
}

/*
 * This function cleans the list of models
 *
 * Models structure
 * t_list *models:
 * 	t_list *next
 * 	void *content
 * 		content->t_face *faces
 * 			faces->t_cor *cors
 * 				cors: int x, int y, int z
 */
static void	clean_models(t_models *models)
{
	int	index;
	int	is_end;

	index = 0;
	is_end = 0;
	while (is_end == 0)
	{
		ft_lstclear(&models[index].model_data, &del);
		clean_faces(models[index].model_faces);
		free(models[index].model_faces);
		if (models[index].id == -1)
			is_end = 1;
		index++;
	}
	free(models);
}

/*
 * This function close the program and free al
 * memory used
 *
 * TO FREE:
 *
 * 	- To use lists function to clean the list
 * 	t_models:
 * 	t_list *model_data
 * 		content: s_cors *cors
 * 	- To free just free the fire the pointer
 * 	t_face *model_faces
 * 	t_face *model_proj
 *
 *
 * 	- To free check if is necessary to free the mlx and win pointers
 * 	t_mlx_data *mlx_data
 * 		s_img *img
 * 			void *img
 * 			char  *addr
 */
void	end_program(t_state *state)
{
	// free mlx data
	mlx_destroy_window(
			state->mlx_data->mlx, state->mlx_data->win);
	mlx_destroy_image(
			state->mlx_data->mlx, state->mlx_data->img->img);
	free(state->mlx_data->img);
	free(state->mlx_data->mlx);
	free(state->mlx_data);

	// to  build the models
	clean_models(state->models);

	// free state
	free(state);
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
	int	increment;
	t_cor	n_pos;

	increment = 100;
	model = state->models[0].model_data;
	n_pos.x = 0;
	n_pos.y = 0;
	n_pos.z = 0;
	if (key == M_FORWARD)
	{
		n_pos.z = increment;
		move_model(model, &n_pos, 1);
		ft_printf("move to forward\n");
	}
	else if (key == M_BACKWARD){
		n_pos.z = increment;
		move_model(model, &n_pos, 1);
		ft_printf("move to backward\n");
	}
	else if (key == M_LEFT){
		n_pos.x = -increment;
		move_model(model,&n_pos, 1);
		ft_printf("move to left\n");
	}
	else if (key == M_RIGHT){
		n_pos.x = increment;
		move_model(model, &n_pos, 1);
		ft_printf("move to right\n");
	}
	refresh_window(state);
}

/*
This function updates the model scale

*/
void	update_m_s(t_state *state, int key)
{
	float	increment;
	t_cor	scl;
	t_list	*model;

	increment = 100;
	scl.x = 0;
	scl.y = 0;
	scl.z = 0;
	model = state->models[0].model_data;
	if (key == S_PLUS)
	{
		scl.x = increment;
		scl.y = increment * 0.2;
		scl.z = increment;
		magnify_model(model, &scl);
		ft_printf("scale +\n");
	}
	else if (key == S_LESS)
	{
		scl.x = -increment;
		scl.y = -increment * 0.2;
		scl.z = -increment;
		magnify_model(model, &scl);
		ft_printf("scale +\n");
	}
	refresh_window(state);
}
void	update_m_r(t_state *state, int key)
{
	t_list	*model;
	float	increment;
	t_cor	n_ang;

	increment = 0.5;
	model = state->models[0].model_data;
	n_ang.x = 0;
	n_ang.y = 0;
	n_ang.z = 0;
	if (key == R_POS_X)
	{
		n_ang.x = increment;
		rotate_model(model, &n_ang);
		ft_printf("rotate to forward\n");
	}
	else if (key == R_NEG_X){
		n_ang.x = increment;
		rotate_model(model, &n_ang);
		ft_printf("rotate to backward\n");
	}
	else if (key == R_NEG_Y){
		n_ang.z = -increment;
		rotate_model(model, &n_ang);
		ft_printf("rotate to left\n");
	}
	else if (key == R_POS_Y){
		n_ang.z = increment;
		rotate_model(model, &n_ang);
		ft_printf("rotate to right\n");
	}
	refresh_window(state);
}
