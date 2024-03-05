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

void	minimize_window(t_mlx_data *mlx_data)
{
	mlx_data = malloc(sizeof(t_mlx_data) * 1);
	if (!mlx_data)
		return ;
	free(mlx_data);
}

void	end_program(t_mlx_data *mlx_data)
{
	mlx_destroy_window(mlx_data->mlx, mlx_data->win);
	mlx_destroy_image(mlx_data->mlx, mlx_data->img->img);
	free(mlx_data->mlx);
	exit(1);
}
