/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangles_builder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:45:36 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/05 13:45:39 by antcampo         ###   ########.fr       */
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
t_cor	*build_triangle(t_list *cur_node, int col_i)
{
	int		face_size;
	t_cor	*model;
	t_list	*temp_node;
	t_cor	*tmp_p;

	face_size = find_face_size(cur_node, col_i);
	tmp_p = (t_cor *) malloc(sizeof(t_cor) * face_size);
	if (!tmp_p)
		return (NULL);
	model = (t_cor *) cur_node->content;
	tmp_p[0] = model[col_i];
	tmp_p[0].id = 0;
	if (model[col_i].id != -1)
	{
		tmp_p[1] = model[col_i + 1];
		tmp_p[1].id = 0;
	}
	if (cur_node->next != NULL)
	{
		temp_node = cur_node->next;
		model = (t_cor *) temp_node->content;
		tmp_p[(face_size - 1)] = model[col_i];
		tmp_p[(face_size - 1)].id = 0;
	}
	tmp_p[(face_size - 1)].id = -1;
	cur_node = NULL;
	return (&tmp_p[0]);
}