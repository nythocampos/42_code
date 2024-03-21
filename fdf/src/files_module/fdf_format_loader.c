/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_format_loader.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:29:19 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/20 16:10:05 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static void	get_longest_line(int cur_line_len, t_state *state)
{
	if (state->models->cols_len < cur_line_len)
		state->models->cols_len = cur_line_len;
}

static t_cor	*load_line(char *line, int row_num, t_state *state)
{
	int		index;
	int		col_i;
	int		cols_num;
	t_cor	*pts_list;

	index = 0;
	col_i = 0;
	if (!line)
		return (NULL);
	cols_num = get_columns_num(line);
	get_longest_line(cols_num, state);
	pts_list = (t_cor *) malloc(sizeof(t_cor) * (cols_num));
	if (!pts_list)
		return (NULL);
	while (line[index] != '\0' && col_i <= (cols_num - 1))
	{
		if (on_item(line, (index + 1)) == 1)
		{
			pts_list[col_i].x = (float) col_i;
			pts_list[col_i].y = (float) get_item_value(line, index);
			pts_list[col_i].z = (float) row_num;
			pts_list[col_i].id = col_i;
			if (state->models->val_len < pts_list[col_i].y)
				state->models->val_len = pts_list[col_i].y;
			col_i++;
		}
		index++;
	}
	pts_list[cols_num - 1].id = -1;
	return (&pts_list[0]);
}

static t_list	*add_node(char *tmp_l, int row_n, t_state *state)
{
	t_cor	*pts_lst;
	t_list	*cur_n;

	if (tmp_l == NULL)
		return (NULL);
	pts_lst = load_line(tmp_l, row_n, state);
	cur_n = ft_lstnew((void *) &pts_lst[0]);
	return (cur_n);
}

t_list	*load_terrain_model(int file_df, t_state *state)
{
	char	*tmp_l;
	t_list	*first_n;
	t_list	*last_n;
	int		row_i;
	t_list	*cur_n;

	row_i = 0;
	last_n = NULL;
	first_n = NULL;
	tmp_l = (char *) malloc(sizeof(char) * 1);
	if (!tmp_l)
		return (NULL);
	while (tmp_l != NULL)
	{
		free(tmp_l);
		tmp_l = get_next_line(file_df);
		cur_n = add_node(tmp_l, row_i, state);
		if (last_n == NULL)
			first_n = cur_n;
		ft_lstadd_back(&last_n, cur_n);
		row_i++;
	}
	free(tmp_l);
	state->models->rows_len = row_i;
	return (first_n);
}
