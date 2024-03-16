/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_format_loader.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:29:19 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/16 03:18:15 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void draw_cor(t_cor *cor, t_mlx_data *mlx)
{
	set_pixel(mlx->img, cor->x, cor->y,
			COLOR_B);
}

static void	load_line(char *line, int row_i, t_state *state)
{
	int		index;
	int		col_i;
	t_cor	*cor;

	index = 0;
	col_i = 0;
	if (line == NULL)
		return ;
	cor = (t_cor *) malloc(sizeof(t_cor) * 1);
	if (!cor)
		return ;
	//ft_printf("LINE: %s %d %d\n", line, state->mlx_data->img->bpp, row_i);
	while (line[index] != '\0')
	{
		if (on_item(line, (index + 1)) == 1)
		{
			cor->x = col_i;
			cor->y = get_item_value(line, index);
			cor->z = row_i;
			initialize_mod(cor, col_i, row_i);
			draw_cor(cor, state->mlx_data);
			col_i++;
		}
		index++;
	}
	free(cor);
}

static void	load_terrain_model(int file_df, t_state *state)
{
	char	*tmp_l;
	int		row_i;

	row_i = 0;
	tmp_l = (char *) malloc(sizeof(char) * 1);
	if (!tmp_l)
		return ;
	while (tmp_l != NULL)
	{
		free(tmp_l);
		tmp_l = get_next_line(file_df);
		load_line(tmp_l, row_i, state);
		row_i++;
	}
	free(tmp_l);
}

/*
* This function is used to choose the process to follow
* considering the format of model to load
*/
void	load_model(char *file_name, t_state *state)
{
	int		fd;
	char	*file_path;

	file_path = ft_strjoin(MAPS_PATH, file_name);
	ft_printf("File name: %s \n", file_path);
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("File %s not found\n", file_path);
		return ;
	}
	free(file_path);
	load_terrain_model(fd, state);
	close(fd);
}
