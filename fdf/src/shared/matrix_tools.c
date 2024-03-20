/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:15:00 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/20 14:29:46 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	get_matrix_size(t_list *node)
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
 * This function initialize the matrix provided to 0
 */
void	initialize_m(float *m, int size)
{
	while (--size >= 0)
		m[size] = 0;
}

void	apply_matrix(t_cor *src, void *mtx)
{
	float	w;
	float	*m;

	m = (float *) mtx;
	src->x = src->x * m[0] + src->y * m[1] + src->z * m[2] + m[3];
	src->y = src->x * m[4] + src->y * m[5] + src->z * m[6] + m[7];
	src->z = src->x * m[8] + src->y * m[9] + src->z * m[10] + m[11];
	w = src->x * m[12] + src->y * m[13] + src->z * m[14] + m[15];
	if (w != 0)
	{
		src->x = src->x / w;
		src->y = src->y / w;
		src->z = src->z / w;
	}
}
