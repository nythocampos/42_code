/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:20:09 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/08 19:56:26 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

/*
 *	TODO: check if is necessary controlle errors here
 */
void	refresh_window(t_state *state)
{
	t_mlx_data	*mlx_data;
	t_models	*models;

	models = state->models;
	mlx_data = state->mlx_data;
	project_model(models[0].model_data);
	mlx_put_image_to_window(
			mlx_data->mlx,
			mlx_data->win,
			mlx_data->img->img, 0, 0);
}

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
		return ; // return error
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
