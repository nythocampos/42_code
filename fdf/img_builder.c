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
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/* 
 * This function set pixels to defined positions on the screen
 * */
static void	set_pixels(t_img *img, t_world_coor world_coor)
{
	int	new_x;
	int	new_y;
	int	a;

	a = 60;
	// convert 3D to 2D
	ft_printf("X: %d, Y: %d, Z: %d\n", world_coor.x, world_coor.y, world_coor.z);
	new_x = convert_3d_to_2d(world_coor.x, world_coor.z, a);
	new_y = convert_3d_to_2d(world_coor.y, world_coor.z, a);
	my_mlx_pixel_put(img->img, new_x, new_y, COLOR);
}

static void	draw_line(char *line, int line_num, t_img *img)
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
	line_num = 0;
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
			world_coor.x = column_num;
			world_coor.y = item_value;
			world_coor.z = line_num;
			set_pixels(img, world_coor);
			column_num++;
			lst_index++;
		}
		index++;
	}
}

//TODO: move this function to other file related with files loading
static void	load_terrain_model(int file_df, t_img *img)
{
	return;
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
		draw_line(temp_line, line_num, img);
		line_num++;
	}
}

void	build_image(t_mlx_data *mlx_data, char *file_name)
{
	int	fd;

	ft_printf("Building img... \n");
	fd = open(file_name, O_RDONLY);
	ft_printf("Setting image address ...\n");
	mlx_data->img.img = mlx_new_image(
		mlx_data->mlx_ptr,
		mlx_data->width,
		mlx_data->hight
			);
	mlx_data->img.addr = mlx_get_data_addr(
		mlx_data->img.img,
		&mlx_data->img.bits_per_pixel,
		&mlx_data->img.line_length,
		&mlx_data->img.endian);
	// Test
	ft_printf("Building pixel test... \n");
	my_mlx_pixel_put(&mlx_data->img, 5, 5, 0x00FF0000);
	// ---
	load_terrain_model(fd, &mlx_data->img);
	mlx_put_image_to_window(
		mlx_data->mlx_ptr,
		mlx_data->win_ptr,
		mlx_data->img.img, 0, 0);
	ft_printf("Image built. \n");
}
