/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangles_builder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:45:36 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/20 15:35:44 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

/*
 *
 * This function builds a triangular face
 */
static void	fill_triangle(t_list *node, int col_i, int row_i, t_state *state)
{
	t_cor	*model;
	t_list	*temp_node;

	model = (t_cor *) node->content;
	initialize_mod(&model[0], col_i, row_i);
	draw_cor(&model[0], state->mlx_data);
	if (model[col_i].id != -1)
	{
		initialize_mod(&model[col_i + 1], col_i, row_i);
		draw_cor(&model[col_i + 1], state->mlx_data);
	}
	if (node->next != NULL)
	{
		temp_node = node->next;
		model = (t_cor *) temp_node->content;
		
		initialize_mod(&model[col_i], col_i, row_i);
		draw_cor(&model[col_i], state->mlx_data);
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
