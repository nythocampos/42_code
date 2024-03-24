/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:20:09 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/24 18:32:45 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static void	initialize_window(t_mlx_data *mlx_data, char *title)
{
	t_img	*img;

	img = (t_img *) malloc(sizeof(t_img) * 1);
	if (!img)
		return ;
	mlx_data->win = mlx_new_window(
			mlx_data->mlx, WIDTH, HEIGHT, title);
	if (mlx_data->win == NULL)
	{
		free(mlx_data->mlx);
		return ;
	}
	img->img = mlx_new_image(mlx_data->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(
			img->img, &img->bpp, &img->size_line, &img->endian);
	mlx_data->img = img;
}

/*
 * This function sets everything nessary to run the window
 */
void	set_window(t_mlx_data *mlx_data, char *title)
{
	initialize_window(mlx_data, title);
}
