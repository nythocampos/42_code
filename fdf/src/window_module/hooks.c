/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:01:05 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/20 15:30:51 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static void	del(void *content)
{
	free(content);
	content = NULL;
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

	ft_lstclear(&state->models->model_data, &del);
	free(state->models);

	// free state
	free(state);
	exit(1);
}
