/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:55:03 by antcampo          #+#    #+#             */
/*   Updated: 2023/12/29 20:03:52 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

// TO CONCIDER: Use an interface to controler the keys pressed
int	handle_keys(int key_num, t_mlx_data *data)
{
	t_ctl *ctl;

	ctl = data->ctl;
	if (key_num == 0xff1b)
	{
		end_program(data);
	} 
	else if(key_num == 65361){ // left
		ctl->ang->x = ctl->ang->x + 10;
	} 
	else if(key_num == 65363){ // right
		ctl->ang->y = ctl->ang->y + 10;
	} 
	else if(key_num == 65362){ // up
		ctl->ang->z = ctl->ang->z + 10;
	} 
	else if(key_num == 65364){ // down
		mlx_clear_window(data->mlx, data->win);
	}
	return (0);
}

void	set_events(t_mlx_data *data)
{
	mlx_key_hook(data->win,  handle_keys, &data);
}
