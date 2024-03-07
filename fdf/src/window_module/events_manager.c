/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:55:03 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/07 19:52:45 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static int	handle_destroy(t_state *state)
{
	end_program(state);
	return (0);
}

// TO CONCIDER: Use an interface to controler the keys pressed
static int	handle_keys(int key_num, t_state *state)
{
	t_mlx_data	*mlx_data;

	mlx_data = state->mlx_data;
	if (key_num == 0xff1b)
		end_program(state);
	if (key_num == 't')
	{
		mlx_put_image_to_window(
			mlx_data->mlx,
			mlx_data->win,
			mlx_data->img->img, 0, 0);
	}
	return (0);
}

static int	handle_expose(t_state *state)
{
	t_mlx_data	*mlx_data;

	mlx_data = state->mlx_data;
	mlx_put_image_to_window(
		mlx_data->mlx,
		mlx_data->win,
		mlx_data->img->img, 0, 0);
	ft_printf("Entry window\n");
	return (0);
}

void	set_events(t_state *state)
{
	t_mlx_data	*mlx_d;

	mlx_d = state->mlx_data;
	mlx_hook(mlx_d->win, 2, 1L << 0, handle_keys, state);
	mlx_hook(mlx_d->win, 12, 1L << 15, handle_expose, state);
	mlx_hook(mlx_d->win, 17, 0, handle_destroy, state);
}
