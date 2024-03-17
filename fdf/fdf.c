/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:50:30 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/16 00:34:05 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 * This function corrects the size
 * and position of the model
 *
 * Linux: x: 90, y: 90, z:0.1
 * Mac: x: ?, y: ?, z: ?
 */
static void	correct_mod(t_list *model_data)
{
	magnify_model(model_data, 50, 50, 0.1);
	move_model(model_data, 0, 0, 0);
}

void	initialize_mod(t_list *model_data)
{
	magnify_model(model_data, 1, 0.1, 0.8);
	rotate_model(model_data, 1.1, 0.2, 0.1);
	correct_mod(model_data);
	move_model(model_data, 100, 200, 1);
	project_model(model_data);
}



int	main(int argc, char *argv[])
{
	t_state		*state;
	t_models	*models;

	//test();
	if (argc != 2)
		return (0);
	state = initialize_state((argc - 1), argv);	
	if (state == NULL || state->models == NULL) // check models and mlx
	{
		ft_printf("Error generating the state\n");
		end_program(state);
		return (0);
	}
	/*ft_printf("OK 1\n");
	end_program(state);
	return (0);*/
	models = state->models;
	//TODO: find a way to render the map
	// while the program is running
	build_image(state, models->model_faces);
	set_events(state);
	mlx_loop(state->mlx_data->mlx);
}

