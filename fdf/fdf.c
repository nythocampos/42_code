/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:50:30 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/08 18:52:19 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char  *argv[])
{
	t_state		*state;
	t_models	*models;

	if (argc < 2)
		return (0);
	state = initialize_state((argc - 1), argv);
	if (state == NULL)
	{
		ft_printf("Error generating the state\n");
		return (0);
	}
	models = state->models;
	build_image(state->mlx_data, models->model_faces);
	set_events(state);
	mlx_loop(state->mlx_data->mlx);
}

