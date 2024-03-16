/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:13:07 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/05 13:17:46 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	get_cols_num(t_cor *pts_list)
{
	int	index;
	int	n_cols;

	index = 0;
	n_cols = 1;
	while (pts_list[index].id != -1)
	{
		index++;
		n_cols++;
	}
	return (n_cols);
}

int	get_rows_num(t_list *model)
{
	int	index;

	index = 1;
	while (model->next != NULL)
	{
		model = model->next;
		index++;
	}
	return (index);
}
