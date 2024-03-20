/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   faces_builder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:36:06 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/20 15:15:57 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static int	get_matrix_size(t_list *node)
{
	int	m_size;
	int	n_rows;
	int	n_cols;

	n_rows = get_rows_num(node);
	n_cols = get_cols_num((t_cor *) node->content);
	m_size = (n_cols * n_rows);
	return (m_size);
}

/*
 * This function builds the faces TODO: considering
 * the type of face needed.
 *
 * Args:
 * 	model (t_list *): a list of nodes, every node contain
 * 	a list of coordinates (t_cor).
 * Return:
 * 	faces_list (t_face *): the list of faces generated
 */
void	build_faces(t_list *node, t_state *state)
{
	int		n_cols;
	int		m_size;
	int		is_last_line;
	int		index;

	is_last_line = 0;
	index = 0;
	n_cols = get_cols_num((t_cor *) node->content);
	m_size = get_matrix_size(node);
	while (is_last_line == 0)
	{
		build_triangles(node, n_cols, &index, state);
		if (node->next == NULL)
			is_last_line = 1;
		else
			node = node->next;
	}
}
