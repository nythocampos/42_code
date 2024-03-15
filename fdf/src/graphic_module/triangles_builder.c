/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangles_builder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:45:36 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/16 00:05:33 by antcampo         ###   ########.fr       */
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
t_cor	*fill_triangle(t_list *node, t_cor *tmp_f, int col_i, int f_len)
{
	t_cor	*model;
	t_list	*temp_node;

	model = (t_cor *) node->content;
	tmp_f[0] = model[col_i];
	tmp_f[0].id = 0;
	if (model[col_i].id != -1)
	{
		tmp_f[1] = model[col_i + 1];
		tmp_f[1].id = 0;
	}
	if (node->next != NULL)
	{
		temp_node = node->next;
		model = (t_cor *) temp_node->content;
		tmp_f[(f_len - 1)] = model[col_i];
		tmp_f[(f_len - 1)].id = 0;
	}
	tmp_f[(f_len - 1)].id = -1;
	return (&tmp_f[0]);
}

void	build_triangles(t_list *node, t_face *faces, int n_cols, int *index)
{
	int		col_i;
	int		f_len;
	t_cor	*tmp_f;

	col_i = 0;
	while (col_i <= (n_cols - 1))
	{
		f_len = find_face_size(node, col_i);
		tmp_f = (t_cor *) malloc(sizeof(t_cor) * f_len);
		if (!tmp_f)
			return ;
		faces[*index].points = fill_triangle(node, tmp_f, col_i, f_len);
		faces[*index].id = *index;
		col_i++;
		*index = *index + 1;
	}
}
