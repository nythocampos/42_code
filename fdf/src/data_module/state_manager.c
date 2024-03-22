/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:43:56 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/20 15:44:14 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

/*
 * TODO: move this function to the window module
 *
 */
static t_mlx_data	*initialize_win(void)
{
	t_mlx_data	*mlx_data;

	mlx_data = (t_mlx_data *) malloc(sizeof(t_mlx_data) * 1);
	if (!mlx_data)
		return (NULL);// end_program
	mlx_data->mlx = mlx_init();
	set_window(mlx_data, "FDF");
	return (mlx_data);
}

t_state	*initialize_state(char **argv)
{
	t_state	*state;

	state = (t_state *) malloc(sizeof(t_state) * 1);
	if (!state)
		return (NULL);
	state->mlx_data = initialize_win();
	if (state->mlx_data == NULL)
	{
		ft_printf("[INITIALIZING WINDOW]\n");
		end_program(state);
		exit(1);
		return (NULL);
	}
	state->models = import_model(argv, state);
	if (state->models == NULL)
	{
		end_program(state);
		ft_printf("[IMPORTING MODELS]\n");
		exit(1);
		return (NULL);
	}
	return (state);
}
