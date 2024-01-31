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

static void  set_pixels()
{
  img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
}

/*
 * This function 
 */
static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static int	get_columns_num(char *line)
{
	int	index;
	int	column_num;

	index = 1;
	column_num = 0;
	while (line[index] != '\0')
	{
		if ((line[index - 1] >= 48 && line[index - 1] <= 57) && 
			(line[index] < 48 || line[index] > 57))
			column_num++;
		index++;
	}
	return (column_num);
}

static int get_item_value(char *str, int end)
{
	int   num;
	char  *str_num;
	int   start;
	int   index;

	start = end;
	index = 0;
	num = 0;
	while (str[start - 1] >= 48 && str[start - 1] <= 57)
		start--;
	str_num = (char *) malloc(sizeof(char) * (end - start + 1));
	if (!str_num)
		return (0);
	while (start <= end)
	{
		str_num[index] = str[start];
		index++;
		start++;
	}
	str_num[index] = '\0';
	num = ft_atoi(str_num);
	free(str_num);
	return (num);
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
