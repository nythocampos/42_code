/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_builder.c                                    :+:      :+:    :+:   */
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
static void	my_mlx_pixel_put(t_frame *frame, int x, int y, int color)
{
	char	*dst;

	dst = frame->addr + (y * frame->line_length + x * (frame->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/* 
 * This function set pixels to defined positions on the screen
 * */
static void	set_pixels(t_frame *frame, t_world_coor world_coor)
{
	int	new_x;
	int	new_y;
	int	a;

	a = 60;
	// convert 3D to 2D
	ft_printf("X: %d, Y: %d, Z: %d\n", world_coor.x, world_coor.y, world_coor.z);
	new_x = convert_3d_to_2d(world_coor.x, world_coor.z, a);
	new_y = convert_3d_to_2d(world_coor.y, world_coor.z, a);
	my_mlx_pixel_put(frame->img, new_x, new_y, COLOR);
}

static void	draw_line(char *line, int line_num, t_frame *frame)
{
	int   	index;
	int   	column_num;
	int   	item_value;
	int	columns_num;
	int	lst_index;
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
			set_pixels(frame, world_coor);
			column_num++;
			lst_index++;
		}
		index++;
	}
}

static void	load_terrain_model(int file_df, t_frame *frame)
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
		draw_line(temp_line, line_num, frame);
		line_num++;
	}
}



t_mlx_data	*build_frame(char *file_name)
{
	int			fd;
	struct s_mlx_data	*mlx_data;
	struct s_frame		*frame;

	ft_printf("Building frame... \n");
	frame = NULL;
	fd = open(file_name, O_RDONLY);
	mlx_data = init_mlx_data();
	frame->addr = mlx_get_data_addr(
		frame->img,
		&frame->bits_per_pixel,
		&frame->line_length,
		&frame->endian);
	load_terrain_model(fd, frame);
	mlx_put_image_to_window(
		mlx_data->mlx_ptr,
		mlx_data->win_ptr,
		frame->img, 0, 0);
	ft_printf("Frame built. \n");
	return (mlx_data);
}
