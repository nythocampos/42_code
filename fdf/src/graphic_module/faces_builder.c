/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   faces_builder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:36:06 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/18 15:08:01 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

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
t_face	*build_faces(t_list *node)
{
	int		n_cols;
	int		m_size;
	int		is_last_line;
	t_face	*faces;
	int		index;

	is_last_line = 0;
	index = 0;
	n_cols = get_cols_num((t_cor *) node->content);
	m_size = get_matrix_size(node);
	faces = (t_face *) malloc(sizeof(t_face) * m_size);
	if (!faces)
		return (NULL);
	while (is_last_line == 0)
	{
		build_triangles(node, faces, n_cols, &index);
		if (node->next == NULL)
			is_last_line = 1;
		else
			node = node->next;
	}
	faces[(m_size) - 1].id = -1;
	return (&faces[0]);
}
