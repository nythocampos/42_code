/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:45:56 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/18 18:31:57 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	draw_triangle(t_list *node, int col_i, t_ipixels_writer *pw, t_state *state)
{
	t_cor	*point;
	t_list	*tmp_n;

	point = (t_cor *) node->content;
	pw->write_pixel(state, &point[col_i], COLOR_B);
	if (point[col_i].id != -1)
		pw->write_pixel(state, &point[col_i + 1], COLOR_B);
	if (node->next != NULL)
	{
		tmp_n = node->next;
		point = (t_cor *) tmp_n->content;
		pw->write_pixel(state, &point[col_i], COLOR_B);
	}
}

/*
 * This function prints the received model
 *
 */
void	print_model(t_list *model, t_ipixels_writer *pw, t_state *state)
{
	int	col_i;
	int	n_cols;

	col_i = 0;
	n_cols = get_cols_num((t_cor *) model->content);
	while (model != NULL)
	{	
		while (col_i <= (n_cols - 1))
		{	
			draw_triangle(model, col_i, pw, state);
			col_i++;
		}
		model = model->next;
	}
}

t_imodel_printer	*create_model_printer()
{
	t_imodel_printer	*m_printer;
	
	m_printer = (t_imodel_printer *) malloc(sizeof(t_imodel_printer) * 1);
	if (!m_printer)
		return (NULL);
	m_printer->print_model = print_model;
	return (m_printer);
}
