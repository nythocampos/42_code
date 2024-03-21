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

/*
 *
 * This function builds a triangular face
 */
static void	fill_triangle(t_list *node, int col_i, t_state *state)
{
	t_cor	*cors;
	t_list	*tmp_node;
	t_cor	*tmp_cors;

	cors = (t_cor *) node->content;
	if (cors[col_i].id != -1)
	{
		draw_vector(&cors[col_i], &cors[col_i + 1], state);
	}
	if (node->next != NULL)
	{
		tmp_node = node->next;
		tmp_cors = (t_cor *) tmp_node->content;
		draw_vector(&cors[col_i], &tmp_cors[col_i], state);
	}
}

void	build_triangles(t_list *node, int n_cols, int *row, t_state *state)
{
	int		col_i;

	col_i = 0;
	while (col_i <= (n_cols - 1))
	{
		fill_triangle(node, col_i, state);
		col_i++;
		*row = *row + 1;
	}
}
