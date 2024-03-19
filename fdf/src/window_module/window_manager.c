/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:20:09 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/19 14:45:33 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

/*
 * TODO: check if is necessary controlle errors here
 */
void	refresh_window(t_state *state)
{
	t_mlx_data	*mlx_data;

	mlx_data = state->mlx_data;
	mlx_put_image_to_window(
			mlx_data->mlx,
			mlx_data->win,
			mlx_data->img->img, 0, 0);
}

static t_img	*initialize_img(t_mlx_data *mlx_data)
{
	t_img	*img;

	img = (t_img *) malloc(sizeof(t_img) * 1);
	if (!img)
		return (NULL);	
	img->img = mlx_new_image(mlx_data->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(
			img->img, &img->bpp, &img->size_line, &img->endian);
	return (img);
}

void	clean_mlx_data(t_mlx_data *mlx_data)
{
	mlx_destroy_window(mlx_data->mlx, mlx_data->win);
	mlx_destroy_image(mlx_data->mlx, mlx_data->img->img);
	free(mlx_data->img);
	free(mlx_data->mlx);
	free(mlx_data);
}

t_mlx_data	*create_mlx_data(void)
{
	t_mlx_data	*mlx_data;

	mlx_data = (t_mlx_data *) malloc(sizeof(t_mlx_data) * 1);
	if (!mlx_data)
		return (NULL);
	mlx_data->mlx = mlx_init();
	mlx_data->win = mlx_new_window(
			mlx_data->mlx, WIDTH, HEIGHT, TITLE);
	if (!mlx_data->win)
	{
		free(mlx_data->mlx);
		return (NULL);
	}
	mlx_data->img = initialize_img(mlx_data);
	return (mlx_data);
}

