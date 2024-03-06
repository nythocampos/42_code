/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:01:05 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/05 13:24:42 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	end_program(t_state *state)
{
	t_mlx_data	*mlx_data;

	mlx_data = state->mlx_data;
	mlx_destroy_window(mlx_data->mlx, mlx_data->win);
	mlx_destroy_image(mlx_data->mlx, mlx_data->img->img);
	//TODO: free all memory used
	free(mlx_data->mlx);
	exit(1);
}
