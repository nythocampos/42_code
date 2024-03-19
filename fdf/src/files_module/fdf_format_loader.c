/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_format_loader.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:29:19 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/19 16:12:18 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//TODO: refactor this function
/*
 * This function recive every line got from the file and
 * extract all values from it, then storage the items in
 * a new node in model_data.
 *
 * Args:
 * 	line (char *): line got from the file.
 * 	row_num (int): number of the line got from the file.
 * 	model_data (t_list *): first node of linked list where
 * 	the model will be storaged.
 * Return:
 * 	0: ERROR
 * 	1: OK
 */
int	load_line(char *line, int row_num, t_list **model_data)
{
	int	index;
	int	col_i;
	int	cols_num;
	t_cor	*cors;
	t_list	*new_node;
	t_list	*last_n;

	index = 0;
	col_i = 0;
	if (line == NULL)
		return (0);
	cols_num = get_columns_num(line);
	cors = (t_cor *) malloc (sizeof(t_cor) * cols_num);
	if (!cors)
		return (0);
	while (line[index] != '\0' && col_i <= cols_num)
	{
		if (on_item(line, (index + 1)) == 1)
		{
			cors[col_i].x = col_i;
			cors[col_i].y = get_item_value(line, index);
			cors[col_i].z = row_num;
			cors[col_i].id = col_i;
			col_i++;
		}
		index++;
	}
	cors[cols_num - 1].id = -1;
	new_node = ft_lstnew((void *) &cors[0]);
	if (!new_node)
		return (0);
	last_n = ft_lstlast(*model_data);
	if (!last_n)
		*model_data = new_node;
	else
		ft_lstadd_back(&last_n, new_node);
	return (1);
}

t_imodel_collector	*create_fdf_collector()
{
	t_imodel_collector	*fdf_collector;

	fdf_collector = (
		t_imodel_collector *) malloc(sizeof(t_imodel_collector));
	if (!fdf_collector)
		return (NULL);
	fdf_collector->collect_data = &load_line;
	return (fdf_collector);
}
