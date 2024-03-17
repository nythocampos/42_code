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
/*static void	correct_mod(t_list *model_data)
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
}*/

t_state	*create_state()
{
	t_state	*state;

	state = (t_state *) malloc(sizeof(t_state) * 1);
	if (!state)
		return (NULL);
	state->mlx_data = create_mlx_data();
	if (!state->mlx_data)
		return (NULL);
	state->models = create_model();
	if (!state->models)
		return (NULL);
	return (state);
}

int	main(int argc, char *argv[])
{
	t_ifile_loader	*file_loader;
	s_imodel_updater *m_updater;
	t_model	*model;
	t_list	*model_data;

	if (argc != 2)
		return (0);	
	state = create_state();
	if (!state)
		return (NULL);
	file_loader = create_file_loader();
	file_loader->load_file(argv, argc, state);
	
	model = get_model(state->models, 1);
	model_data = model->model_data;
	m_updater->scale_model(model_data, 1, 0.1, 0.8)
	m_updater->rotate_model(model_data, 1.1, 0.2, 0.1);

	m_updater->magnify_model(model_data, 50, 50, 0.1);
	m_updater->move_model(model_data, 0, 0, 0);

	m_updater->move_model(model_data, 100, 200, 1);
	m_updater->project_model(model_data);

	//TODO: find a way to render the map
	// while the program is running
	// TODO: call model_printer

	set_events(state);
	mlx_loop(state->mlx_data->mlx);
}

