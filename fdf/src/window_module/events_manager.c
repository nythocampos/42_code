/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:55:03 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/15 17:38:17 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static int	handle_destroy(t_state *state)
{
	end_program(state);
	return (0);
}

static int	handle_keys(int key, t_state *state)
{
	t_mlx_data	*mlx_data;

	mlx_data = state->mlx_data;
	if (key == 0xff1b || key == 53)
		end_program(state);
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
