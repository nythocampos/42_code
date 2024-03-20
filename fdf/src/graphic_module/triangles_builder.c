/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangles_builder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:45:36 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/20 16:16:56 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static int	find_face_size(t_list *cur_node, int col_i)
{
	int		face_size;
	t_cor	*model;

	face_size = 3;
	model = (t_cor *) cur_node->content;
	if (model[col_i].id == -1)
		face_size = face_size - 1;
	if (cur_node->next == NULL)
		face_size = face_size - 1;
	return (face_size);
}
/*
 *
 * This function builds a triangular face
 */
static void	fill_triangle(t_list *node, int col_i, int row_i, t_state *state)
{
	t_cor	*cors;
	t_list	*tmp_node;
	t_cor	*tmp_cors;
	int		f_size;

	f_size = find_face_size(node, col_i);
	cors = (t_cor *) node->content;
	initialize_mod(&cors[0], col_i, row_i);
	//draw_cor(&cors[0], state->mlx_data);
	if (cors[col_i].id != -1)
	{
		initialize_mod(&cors[col_i + 1], col_i, row_i);
		//draw_cor(&cors[col_i + 1], state->mlx_data);
		draw_line(state->mlx_data, &cors[0], &cors[col_i + 1]);
	}
	if (node->next != NULL)
	{
		tmp_node = node->next;
		tmp_cors = (t_cor *) tmp_node->content;
		
		initialize_mod(&tmp_cors[(f_size -1)], col_i, row_i);
		//draw_cor(&cors[col_i], state->mlx_data);
		draw_line(state->mlx_data, &cors[(f_size -1)], &tmp_cors[col_i]);
	}
}

void	build_triangles(t_list *node, int n_cols, int *row, t_state *state)
{
	int		col_i;

	col_i = 0;
	while (col_i <= (n_cols - 1))
	{
		fill_triangle(node, col_i, *row, state);
		col_i++;
		*row = *row + 1;
	}
}
