/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:01:05 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/15 22:51:23 by antcampo         ###   ########.fr       */
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
 * 		content->t_cors *cors
 * 				cors: int x, int y, int z
 */
static void	clean_models(t_models *models)
{
	return ;
	int	index;
	int	is_end;

	index = 0;
	is_end = 0;
	if (models == NULL)
		return ;
	while (is_end == 0)
	{
		if (models[index].model_data)
			ft_lstclear(&models[index].model_data, &del);
		if (models[index].model_faces)
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

	ft_lstclear(&state->models->model_data, &del);
	free(state->models->model_data);
	clean_faces(state->models->model_faces);
	free(state->models->model_faces);
	free(state->models);

	// free state
	free(state);
	exit(1);
}
