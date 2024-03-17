/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_format_loader.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:29:19 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/16 00:34:08 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static t_cor	*load_line(char *line, int row_num, t_list *model)
{
	int	index;
	int	col_i;
	int	cols_num;
	t_cor	*cors;
	t_list	*new_node;

	index = 0;
	col_i = 0;
	cols_num = get_columns_num(line);
	cors = (t_cor *) malloc (sizeof(t_cor) * cols_num);
	if (!cors)
		return (NULL);
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
	ft_lstadd_back(ft_lstlast(model), new_node);
}

t_imodel_collector	*create_fdf_collector()
{
	t_imodel_collector	*fdf_collector;

	fdf_collector = (
		t_imodel_collector *) malloc(sizeof(t_imodel_collector));
	if (!fdf_collector)
		return (NULL);
	fdf_collector->collect_data = load_line;
	return (fdf_collector);
}
