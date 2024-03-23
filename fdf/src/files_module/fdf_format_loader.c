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

static t_cor	*load_line(char *line, int row_i, t_state *state)
{
	int			index;
	t_data_extractor	*d_ext;
	t_cor			*cor;

	d_ext = (t_data_extractor *) malloc(sizeof(t_data_extractor));
	if (!d_ext)
		return (NULL);
	d_ext = create_data_extractor();
	cor = d_ext->extract_items(row_i, line);
	free(d_ext);
	return (cor);
}

static t_list	*add_node(char *tmp_l, int row_i, t_state *state)
{
	t_cor	*pts_lst;
	t_list	*cur_n;
	int	cols_n;

	if (tmp_l == NULL)
		return (NULL);
	get_longest_line(cols_n, state);
	pts_lst = load_line(tmp_l, row_i,  state);
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
		is_garbage(tmp_l);
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
