/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_processor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:47:13 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/20 14:29:44 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//TODO: find memory error
void	process_lists(t_list *node, void *data, void (*f)(t_cor *, float,float,float))
{
	int		col_i;
	int		is_last_line;
	int		col_n;
	t_cor	*cor_lst;

	col_i = 0;
	col_n = get_cols_num(node->content);
	is_last_line = 0;
	while (is_last_line == 0)
	{
		cor_lst = (t_cor *) node->content;
		while (col_i <= (col_n - 1))
		{
			f(&cor_lst[col_i], data);
			col_i++;
		}
		col_i = 0;
		if (node->next == NULL)
			is_last_line = 1;
		else
			node = node->next;
	}
}
