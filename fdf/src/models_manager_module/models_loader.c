/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models_loader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:45:15 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/20 15:19:45 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

/*
* This function is used to choose the process to follow
* considering the format of model to load
*/
static t_list	*load_model(char *file_name)
{
	t_list	*model;
	int		fd;
	char	*file_path;

	file_path = ft_strjoin(MAPS_PATH, file_name);
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("File %s not found\n", file_path);
		return (NULL);
	}
	free(file_path);
	model = load_terrain_model(fd);
	close(fd);
	return (model);
}

t_models	*import_model(char **argv, t_state *state)
{
	t_models	*models;

	models = (t_models *) malloc(sizeof(t_models) * 1);
	if (!models)
		return (NULL);
	models->model_data = load_model(argv[1]);
	if (models->model_data == NULL)
		return (NULL);
	build_faces(models->model_data, state);
	models->id = -1;
	return (models);
}
