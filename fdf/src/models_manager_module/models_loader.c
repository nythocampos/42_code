/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models_loader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:45:15 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/07 19:50:09 by antcampo         ###   ########.fr       */
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
	ft_printf("File name: %s \n", file_path);
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

t_models	*import_models(int n_mod, char **argv)
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
}
