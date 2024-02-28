/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_format_loader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:29:19 by antcampo          #+#    #+#             */
/*   Updated: 2024/01/31 19:21:53 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_w_cor	*load_line(char *line, int row_num)
{
	int   	index;
	int   	col_num;
	int	cols_quantity;
	t_w_cor	*pts_list;

	index = 1;
	col_num = 1;
	cols_quantity = get_columns_num(line);
	pts_list = NULL;
	ft_printf("cols quantity: %d\n", cols_quantity);
	ft_printf("OK 1 col num: %d\n\n", col_num);
	pts_list = (t_w_cor *) malloc(sizeof(t_w_cor) * (cols_quantity + 1));
	if (!pts_list)
		return (NULL);
	
	while (line[index] != '\0' && col_num <= cols_quantity)
	{
		if (on_item(line, index) == 1) 
		{			
			pts_list[col_num].x = col_num - 1;
			pts_list[col_num].y = get_item_value(line, index);
			pts_list[col_num].z = row_num;
			pts_list[col_num].id = col_num - 1;
			ft_printf("x:%d, ", pts_list[col_num].x);
			ft_printf("y:%d,", pts_list[col_num].y);
			ft_printf("z:%d,", pts_list[col_num].z);
			ft_printf("id:%d,", pts_list[col_num].id);
			ft_printf("col num: %d\n\n", col_num);
			col_num++;
		}
		index++;
	}
	pts_list[col_num - 1].id = -1;
	return(&pts_list[0]);
}

//TODO: move this function to other file related with files loading
t_list	*load_terrain_model(int file_df)
{
	char	*temp_line;
	t_list	*first_node;
	t_list	*cur_node;
	t_list	*last_node;
	int	row_num;
	t_w_cor	*pts_list;

	row_num = 0;
	last_node = NULL;
	cur_node = NULL;
	temp_line = (char *) malloc(sizeof(char) * 1);
	if (!temp_line)
		return (NULL);
	while (temp_line != NULL)
	{
		free(temp_line);
		temp_line = get_next_line(file_df);
		ft_printf("line: %s\n", temp_line);	
		if (temp_line != NULL)
		{
			pts_list = load_line(temp_line, row_num);
			cur_node = ft_lstnew((void *) pts_list);
			if (last_node == NULL)
				first_node = cur_node;
			ft_lstadd_back(&last_node, cur_node);
		}
		row_num++;
	}
	free(temp_line);
	// Free pointers cur, last
	return (first_node);
}

