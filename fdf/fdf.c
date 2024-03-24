/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:50:30 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/24 18:23:03 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_state		*state;

	if (argc != 2)
		return (0);
	state = initialize_state(argv);
	if (state == NULL || state->models == NULL)
	{
		ft_printf("Error generating the state\n");
		end_program(state);
		return (0);
	}
	set_events(state);
	mlx_loop(state->mlx_data->mlx);
}
