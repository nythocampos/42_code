/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:01:05 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/16 02:05:31 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

/*
 * This function close the program and free al
 * memory used
 *
 * TO FREE:
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

	// free state
	free(state);
	exit(1);
}
