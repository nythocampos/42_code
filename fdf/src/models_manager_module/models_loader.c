/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models_loader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:45:15 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/16 01:33:30 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

/*t_models	*import_models(int n_mod, char **argv)
{
	t_models	*models;
	int			index;

	models = (t_models *) malloc(sizeof(t_models) * n_mod);
	if (!models)
		return (NULL);
	index = 0;
	while (index < n_mod)
	{
		models[index].model_data = load_model(argv[index + 1]);
		if (models[index].model_data == NULL)
			return (NULL);
		initialize_mod(models[index].model_data, index);
		models[index].model_faces = build_faces(models[index].model_data);
		models[index].id = index;
		index++;
	}
	models[n_mod - 1].id = -1;
	return (models);
}*/

t_models	*import_model(char **argv)
{
	t_models	*models;

	models = (t_models *) malloc(sizeof(t_models) * 1);
	if (!models)
		return (NULL);
	models->model_data = load_model(argv[1]);
	if (models->model_data == NULL)
		return (NULL);
	initialize_mod(models->model_data, 1);
	/*models->model_faces = NULL; 
	models->id = -1;
	return (models);*/
	models->model_faces = build_faces(models->model_data);
	if (models->model_faces == NULL)
		return (NULL);
	models->id = -1;
	return (models);
}
