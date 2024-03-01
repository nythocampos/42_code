/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_builder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:12:50 by antcampo          #+#    #+#             */
/*   Updated: 2024/01/31 20:08:41 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

/*
 * This function the pixels direct to the space of memory
 */
static void	set_pixel(t_img *img, int x, int y, int color)
{
	int	offset;
	
	offset = (img->line_length *y) + (x*(img->bits_per_pixel/8));
	*((unsigned int*)(offset + img->addr)) = color;
}

/* 
 * This function draw the faces 
 * */
static void	draw_model(t_mlx_data *mlx_data, t_face *faces_lst)
{
	int	faces_i;
	int	pts_i;
	int	end_faces;
	int	end_pts;
	t_s_cor	*points;

	faces_i = 0;
	pts_i = 0;
	end_faces = 0;
	end_pts = 0;
	while(end_faces == 0)
	{
		points = faces_lst[faces_i].points;
		while(end_pts == 0)
		{	
			set_pixel(
				mlx_data->img,
				points[pts_i].x,
				points[pts_i].y,
				COLOR_B);
			pts_i++;
			if (points[pts_i].id == -1)
				end_pts = 1;
		}
		pts_i = 0;
		end_pts = 0;
		faces_i++;
		if (faces_lst[faces_i].id == -1)
			end_faces = 1;
	}
}

static void	set_background(t_mlx_data *mlx_data)
{
	int	x_index;
	int	y_index;

	x_index = 0;
	y_index = 0;
	while(y_index < HEIGHT)
	{
		while(x_index < WIDTH)
		{	
			set_pixel(mlx_data->img, x_index, y_index, COLOR_A);
			x_index++;
		}
		x_index = 0;
		y_index++;
	}
}

void	build_image(t_mlx_data *mlx_data, t_face *faces_lst)
{
	t_img	img;

	ft_printf("Building img... \n");
	ft_printf("Setting image address ...\n");
	img.img = mlx_new_image(
		mlx_data->mlx,
		mlx_data->width,
		mlx_data->hight
		);
	img.addr = mlx_get_data_addr(
		img.img,
		&img.bits_per_pixel,
		&img.line_length,
		&img.endian);
	
	mlx_data->img = &img;
	ft_printf("Drawing background... \n");
	set_background(mlx_data);
	ft_printf("Drawing model... \n");
	draw_model(mlx_data, faces_lst);

	mlx_put_image_to_window(
		mlx_data->mlx,
		mlx_data->win,
		img.img, 0, 0);

	ft_printf("Image built. \n");
}
