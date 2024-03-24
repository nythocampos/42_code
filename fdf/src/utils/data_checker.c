/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:21:58 by anthony           #+#    #+#             */
/*   Updated: 2024/03/24 18:22:12 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	get_longest_line(int cur_line_len, t_state *state)
{
	if (state->models->cols_len < cur_line_len)
		state->models->cols_len = cur_line_len;
}

void	get_largest_item(float item, t_state *state)
{
	if (state->models->val_len < item)
		state->models->val_len = item;
}

/*
 * This function checks if the
 * character could be a part of a
 * valid data in decimal or hexadecimal.
 *
 */
static int	is_valid(char c)
{
	if (ft_isdigit(c)
		|| c == '-'
		|| (ft_tolower(c) >= 'a'
			&& ft_tolower(c) <= 'f'))
		return (1);
	return (0);
}

void	is_garbage(char *tmp_l)
{
	int	index;

	index = 0;
	if (tmp_l == NULL)
		return ;
	while (tmp_l[index] != '\0')
	{
		if (is_valid(tmp_l[index]) == 0)
		{
			free(tmp_l);
			ft_printf("Invalid data found in the file\n");
			exit (1);
			return ;
		}
		index++;
	}
}
