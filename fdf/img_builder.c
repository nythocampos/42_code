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

#include "fdf.h"

/*
 * This function 
 */
static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;
	
	offset = (img->line_length *y) + (x*(img->bits_per_pixel/8));
	*((unsigned int*)(offset + img->addr)) = color;
}

/* 
 * This function set pixels to defined positions on the screen
 * */
static void	set_pixels(t_mlx_data *mlx_data, t_world_coor *world_coor)
{
	int	new_x;
	int	new_y;
	int	a;

	a = 90;
	// convert 3D to 2D
	ft_printf("X: %d, Y: %d, Z: %d\n", world_coor->x, world_coor->y, world_coor->z);
	new_x = convert_3d_to_2d(world_coor->x, world_coor->z, a);
	ft_printf("new_x: %d\n", new_x);
	new_y = convert_3d_to_2d(world_coor->y, world_coor->z, a);
	ft_printf("new_y: %d\n", new_y);
	new_x = new_x + (mlx_data->width/2);
	new_y = new_y + (mlx_data->hight/2);
	my_mlx_pixel_put(mlx_data->img, new_x, new_y, 0x33FFC4);
}

static void	draw_line(char *line, int line_num, t_mlx_data *mlx_data)
{
	int   	index;
	int   	column_num;
	int   	item_value;
	int	columns_num;
	int	lst_index;
	// !FIX world_coor
	t_world_coor	world_coor;

	index = 1;
	lst_index = 0;
	column_num = 0;
	if (!line)
		return;
	columns_num = get_columns_num(line);
	while (line[index] != '\0' && lst_index < columns_num)
	{
		if ((line[index - 1] >= 48 && line[index - 1] <= 57) && 
			(line[index] < 48 || line[index] > 57))
		{
			item_value = get_item_value(line, index);

			//X: column_num;
			//Y: item_value; !!!! FIX: Y item_value
			//Z: line_num;
			world_coor.x = (column_num * 100);
			world_coor.y = (item_value * 100);
			world_coor.z = (line_num * 100);
			set_pixels(mlx_data, &world_coor);
			column_num++;
			lst_index++;
		}
		index++;
	}
}

//TODO: move this function to other file related with files loading
static void	load_terrain_model(int file_df, t_mlx_data *mlx_data)
{
	int	line_num;
	char	*temp_line;

	line_num = 0;
	temp_line = (char *) malloc(sizeof(char) * 1);
	if (!temp_line)
		return;
	while (temp_line)
	{
		free(temp_line);
		temp_line = get_next_line(file_df);
		draw_line(temp_line, line_num, mlx_data);
		line_num++;
	}
}

static void	set_background(t_mlx_data *mlx_data, int color)
{
	for (int y = 0; y < mlx_data->hight; ++y)	
	{
		for (int x = 0; x < mlx_data->width; ++x)
		{
			my_mlx_pixel_put(
				mlx_data->img,
				x, 
				y, 
				color);
		}
	}
}

void	build_image(t_mlx_data *mlx_data, char *file_name)
{
	int	fd;
	t_img	img;

	ft_printf("Building img... \n");
	fd = open(file_name, O_RDONLY);
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
	// Test
	ft_printf("Building pixel test... \n");
	
	mlx_data->img = &img;	
	set_background(mlx_data, 0x00000000);
	//my_mlx_pixel_put(mlx_data->img, 5, 5, 0x33FFC4);
	//my_mlx_pixel_put(mlx_data->img, 10, 10, 0x33FFC4);
	// ---
	load_terrain_model(fd, mlx_data);

	mlx_put_image_to_window(
		mlx_data->mlx,
		mlx_data->win,
		img.img, 0, 0);

	ft_printf("Image built. \n");
}
