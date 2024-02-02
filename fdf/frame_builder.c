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
 * This function set pixels to defined positions on the screen
 * */
static void  set_pixels()
{
	int	width;
	int	hight;

	width = 1920;
	hight = 1080;
	img.img = mlx_new_image(mlx, width, hight);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
}

/*
 * This function 
 */
static void	my_mlx_pixel_put(t_frame *frame, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * frame->line_length + x * (frame->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}



static void	draw_line(char *line, int line_num)
{
	int   					index;
	int   					column_num;
	int   					item_value;
	int						columns_num;
	int						lst_index;

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
			// !!!! FIX: Y item_value
			//Y: item_value;
			//Z: line_num;
			ft_printf("X: %d, Y: %d, Z: %d\n", column_num, item_value, line_num);

			column_num++;
			lst_index++;
		}
		index++;
	}
}

static void	load_terrain_model(int file_df)
{
	int   					line_num;
	char  					*temp_line;

	line_num = 0;
	temp_line = (char *) malloc(sizeof(char) * 1);
	if (!temp_line)
		return;
	while (temp_line)
	{
		free(temp_line);
		temp_line = get_next_line(file_df);
		draw_line(temp_line, line_num);
		line_num++;
	}
}


void	build_frame(char *file_name)
{
	int	fd;

	fd	= open(file_name, O_RDONLY);
	load_terrain_model(fd);
	ft_printf("Build frame \n");
}
