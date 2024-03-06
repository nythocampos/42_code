/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:55:03 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/05 13:23:38 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

// TO CONCIDER: Use an interface to controler the keys pressed
int	handle_keys(int key_num, t_mlx_data *data)
{
	if (key_num == 0xff1b)
		end_program(data);
	return (0);
}

int	handle_expose(t_mlx_data *data)
{
	// ADD REFRESH IMAGE
}

void	set_events(t_state *data)
{
	mlx_hook(data->win, 2, handle_keys, &data);
	t_mlx_data(data->win, 12, handle_expose, &data);
}
