/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_format_loader.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:29:19 by antcampo          #+#    #+#             */
/*   Updated: 2024/01/31 19:21:53 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static t_cor	*load_line(char *line, int row_num)
{
	int   	index;
	int   	col_i;
	int	cols_num;
	t_cor	*pts_list;

	index = 0;
	col_i = 0;
	ft_printf("LINE: %s\n", line);
	cols_num = get_columns_num(line);
	pts_list = (t_cor *) malloc(sizeof(t_cor) * (cols_num));
	if (!pts_list)
		return (NULL);
	while (line[index] != '\0' && col_i <= cols_num)
	{
		if (on_item(line, (index + 1)) == 1)
		{
			pts_list[col_i].x =  col_i;
			pts_list[col_i].y =  get_item_value(line, index);
			pts_list[col_i].z =  row_num;
			pts_list[col_i].id = col_i;

			//pts_list[col_i].z =  (11 - (pts_list[col_i].z * SCALE_Z));
			
			col_i++;
		}
		index++;
	}
	pts_list[cols_num - 1].id = -1;
	return(&pts_list[0]);
}

//TODO: move this function to other file related with files loading
t_list	*load_terrain_model(int file_df)
{
	char	*temp_line;
	t_list	*first_node;
	t_list	*cur_node;
	t_list	*last_node;
	int	row_i;
	t_cor	*pts_lst;

	row_i = 0;
	last_node = NULL;
	cur_node = NULL;
	temp_line = (char *) malloc(sizeof(char) * 1);
	if (!temp_line)
		return (NULL);
	while (temp_line != NULL)
	{
		free(temp_line);
		temp_line = get_next_line(file_df);
		if (temp_line != NULL)
		{
			pts_lst = load_line(temp_line, row_i);
			cur_node = ft_lstnew((void *) &pts_lst[0]);
			if (last_node == NULL)
				first_node = cur_node;
			ft_lstadd_back(&last_node, cur_node);
		}
		row_i++;
	}
	free(temp_line);
	cur_node = NULL;
	last_node = NULL;
	return (first_node);
}

