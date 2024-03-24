/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_format_loader.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:29:19 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/24 18:18:57 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static t_cor	*load_line(char *line, int row_i, t_state *state)
{
	t_data_extractor	*d_ext;
	t_cor				*cor;

	d_ext = create_data_extractor();
	cor = d_ext->extract_items(row_i, line, state);
	free(d_ext);
	return (cor);
}

static t_list	*add_node(char *tmp_l, int row_i, t_state *state)
{
	t_cor	*pts_lst;
	t_list	*cur_n;

	if (tmp_l == NULL)
		return (NULL);
	pts_lst = load_line(tmp_l, row_i, state);
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
