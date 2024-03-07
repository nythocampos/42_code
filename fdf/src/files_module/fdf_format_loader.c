/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_format_loader.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:29:19 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/07 21:25:10 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static t_cor	*load_line(char *line, int row_num)
{
	int		index;
	int		col_i;
	int		cols_num;
	t_cor	*pts_list;

	index = 0;
	col_i = 0;
	cols_num = get_columns_num(line);
	pts_list = (t_cor *) malloc(sizeof(t_cor) * (cols_num));
	if (!pts_list)
		return (NULL);
	while (line[index] != '\0' && col_i <= cols_num)
	{
		if (on_item(line, (index + 1)) == 1)
		{
			pts_list[col_i].x = col_i;
			pts_list[col_i].y = get_item_value(line, index);
			pts_list[col_i].z = row_num;
			pts_list[col_i].id = col_i;
			col_i++;
		}
		index++;
	}
	pts_list[cols_num - 1].id = -1;
	return (&pts_list[0]);
}

t_list	*add_node(char *tmp_l, int row_n)
{
	t_cor	*pts_lst;
	t_list	*cur_n;

	if (tmp_l == NULL)
		return (NULL);
	ft_printf("--->%s\n", tmp_l);
	pts_lst = load_line(tmp_l, row_n);
	cur_n = ft_lstnew((void *) &pts_lst[0]);
	return (cur_n);
}

t_list	*load_terrain_model(int file_df)
{
	char	*tmp_l;
	t_list	*first_n;
	t_list	*last_n;
	int		row_i;
	t_list	*cur_n;

	row_i = 0;
	last_n = NULL;
	tmp_l = (char *) malloc(sizeof(char) * 1);
	if (!tmp_l)
		return (NULL);
	while (tmp_l != NULL)
	{
		free(tmp_l);
		tmp_l = get_next_line(file_df);
		cur_n = add_node(tmp_l, row_i);
		if (last_n == NULL)
			first_n = cur_n;
		ft_lstadd_back(&last_n, cur_n);
		row_i++;
	}
	free(tmp_l);
	return (first_n);
}
