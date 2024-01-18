/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:01:05 by antcampo          #+#    #+#             */
/*   Updated: 2024/01/18 17:52:18 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	minimize_window(t_mlx_data *data){}

void	end_program(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
  	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	free(data->mlx_ptr);
	exit(1);
}
