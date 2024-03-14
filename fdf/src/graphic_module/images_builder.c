/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_builder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:12:50 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/14 18:31:32 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

/*
 * This function the pixels direct to the space of memory
 * TODO: move this to a better place
 */
void	set_pixel(t_img *img, int x, int y, int color)
{
	int	offset;

	if (x > WIDTH || y > HEIGHT || x < 0 || y < 0)
		return ;
	offset = (img->size_line * y) + (x * (img->bpp / 8));
	//ft_printf("offset:%d \n", offset);
	*((unsigned int *)(offset + img->addr)) = color;
}

static void	set_background(t_mlx_data *mlx_data)
{
	int	x_index;
	int	y_index;

	x_index = 0;
	y_index = 0;
	while (y_index < HEIGHT)
	{
		while (x_index < WIDTH)
		{
			set_pixel(mlx_data->img, x_index, y_index, COLOR_A);
			x_index++;
		}
		x_index = 0;
		y_index++;
	}
}

/* 
 * This function draw the faces 
 * */
static void	draw_model(t_mlx_data *mlx_data, t_face *faces_lst)
{
	int		faces_i;
	int		end_faces;
	t_cor	*points;

	faces_i = 0;
	end_faces = 0;
	while (end_faces == 0)
	{
		points = faces_lst[faces_i].points;
		draw_face(mlx_data, points);
		if (faces_lst[faces_i].id == -1)
			end_faces = 1;
		faces_i++;
	}
}

void	build_image(t_mlx_data *mlx_data, t_face *faces_lst)
{
	ft_printf("Building image... \n");
	set_background(mlx_data);
	draw_model(mlx_data, faces_lst);
	ft_printf("Image built. \n");
}
