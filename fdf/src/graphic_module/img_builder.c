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

	if (x > WIDTH || y > HEIGHT || x < 0 || y < 0)	
		return;
	offset = (img->line_length *y) + (x*(img->bits_per_pixel/8));
	*((unsigned int*)(offset + img->addr)) = color;
}

static void	draw_line(t_mlx_data *mlx, t_s_cor *a, t_s_cor *b)
{
	int	dy;
	int	dx;
	int	step_x;
	int	step_y;
	int	temp_x;
	int	temp_y;
	int	p;

	dy = (int) (b->y - a->y);
	dx = (int) (b->x - a->x);
	if (dx > 0){
		step_x = 1;
	} else {
		step_x = -1;
		dx = -dx;
	}
	if (dy > 0) {
		step_y = 1;
	} else {
		step_y = -1;
		dy = -dy;
	}

	// Draw pixels between two points
	temp_x = (int) a->x;
	temp_y = (int) a->y;

	if (dx >= dy)
	{
		p = 2 * dy - dx;
		while (temp_x != b->x)
		{
			set_pixel(
				mlx->img,
				temp_x,
				temp_y,
				COLOR_B);
			temp_x = temp_x + step_x;
			if (p >= 0)
			{
				temp_y = temp_y + step_y;
				p = p - (2 * dx);
			}
			p = p + (2 * dy);
		}
	}
	else
	{
		p = 2 * dx - dy;
		while (temp_y != b->y)
		{
			set_pixel(
				mlx->img,
				temp_x,	
				temp_y,
				COLOR_B);
			temp_y = temp_y + step_y;
			if (p >= 0)
			{
				temp_x = temp_x + step_x;
				p = p - (2 * dy);
			}
			p = p + (2 * dx);
		}
	}
}

static void	draw_face(t_mlx_data *mlx_data, t_s_cor *points)
{
	int	pts_i;
	int	end_pts;
	t_s_cor	*a;
	t_s_cor	*b;

	pts_i = 0;
	end_pts = 0;
	while(end_pts == 0)
	{
		a = &points[pts_i];
		//ft_printf("A x:%d y:%d\n",(int) a->x, (int) a->y);
		if (points[pts_i].id == -1)
		{
			b = &points[0];
			end_pts = 1;
		}
		else 
		{
			b = &points[pts_i + 1];
		}
		pts_i++;
		//ft_printf("B x:%d y:%d\n",(int) b->x, (int) b->y);
		draw_line(mlx_data, a, b);
		//ft_printf("Line writed\n");
	}
}

/* 
 * This function draw the faces 
 * */
static void	draw_model(t_mlx_data *mlx_data, t_face *faces_lst)
{
	int	faces_i;
	int	end_faces;
	t_s_cor	*points;

	faces_i = 0;
	end_faces = 0;
	while(end_faces == 0)
	{
		points = faces_lst[faces_i].points;
		//ft_printf("0 point X; %d\n", (int)points[0].x);
		draw_face(mlx_data, points);
		//ft_printf("Face id:%d\n",faces_lst[faces_i].id);	
		if (faces_lst[faces_i].id == -1)
			end_faces = 1;
		faces_i++;
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

	/*
	ft_printf("null %d\n",faces_lst[0].id);
	t_s_cor *points;
	points = (t_s_cor *) malloc (sizeof(t_s_cor)*3);
	points[0].x = 200;
	points[0].y = 200;
	points[0].id = 0;
	points[1].x = 500;
	points[1].y = 200;
	points[1].id = 0;
	points[2].x = 700;
	points[2].y = 700;
	points[2].id = -1;
	t_face	*test_face;

	test_face = (t_face *) malloc (sizeof(t_face) * 2);
	test_face[0].points = &points[0];
	test_face[0].id = -1;
	// draw_face(mlx_data, &points[0]); // OK
	// draw_line(mlx_data, &points[0], &points[1]);
	draw_model(mlx_data, test_face);*/

	draw_model(mlx_data, faces_lst);
	ft_printf("Model drawn\n");
	mlx_put_image_to_window(
		mlx_data->mlx,
		mlx_data->win,
		img.img, 0, 0);

	ft_printf("Image built. \n");
}
