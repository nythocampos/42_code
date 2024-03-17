/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:01:41 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/15 21:05:32 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"



/*
 * This function cleans the list of models
 *
 * Models structure
 * t_list *models:
 * 	t_list *next
 * 	void *content
 * 		content->t_cors *cors
 * 				cors: int x, int y, int z
 */
void	clean_models(t_models *models)
{
	return ;
	int	index;
	int	is_end;

	index = 0;
	is_end = 0;
	if (models == NULL)
		return ;
	while (is_end == 0)
	{
		if (models[index].model_data)
			ft_lstclear(&models[index].model_data, &del);
		if (models[index].model_faces)
			clean_faces(models[index].model_faces);
		free(models[index].model_faces);
		if (models[index].id == -1)
			is_end = 1;
		index++;
	}
	free(models);
	models = NULL;
}

/*
 * This function must be able to be called just if there is not models
 * created
 * TODO: check this
 */
t_list	*create_models()
{
	t_list	*models;

	models = (char *) malloc(sizeof(char) * 1);
	if (models)
		return (NULL);
	models = ft_lstnew((void *) NULL);
	return (models);
}

/*
 * This function get a a model from the models list
 */
t_model	*get_model(t_list *models_list, int id)
{
	int	index;

	index = 0;
	while (models_list != NULL)
	{
		if (index == id)
			return ((t_model *) models_list->content);
		index++;
		models_list = models_list->next;
	}
	return (NULL);
}

/*
 * This function add a new t_model object in a node to the
 * models list
 */
void	set_model(t_list *models, t_model *model)
{
	t_list	*cur_n;

	cur_n = ft_lstnew((void *) model);
	if (!cur_n)
		return ;
	ft_lstadd_back(ft_lstlast(models), cur_n);
}

t_imodels	*create_models_manager()
{
	t_imodels imodels;

	imodels = (imodels *) malloc (sizeof(imodels) * 1);
	if (!imodels)
		return (NULL);
	imodel->create_models = create_models;
	imodel->clean_models = clean_models;
	imodel->set_model = set_model;
	imodel->get_model = get_model;
	return (imodels);
}

