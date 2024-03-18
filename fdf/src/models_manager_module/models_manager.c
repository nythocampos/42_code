/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:01:41 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/18 19:45:02 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

/*
 * This function cleans the list of models
 * TO FIX: clean all data in models
 *	t_list models
 *	^
 *	* t_list *model
 *	* t_list *model
 *	* t_list *model
 *	* t_list *model
 *
 *	t_list *model
 *	^
 *	* t_cor *cor
 *	* t_cor	*cor
 *	* t_cor	*cor
 *	* t_cor	*cor
 */
void	clean_models(t_list *models_lst)
{
	if (models_lst == NULL)
		return ;
	// TODO: go through all models
	if (models_lst)
			ft_lstclear(&models_lst, &del);
}

/*
 * This function must be able to be called just if there is not models
 * created
 * TODO: check this
 */
t_list	*create_models_list()
{
	t_list	*models;

	models = (t_list *) malloc(sizeof(t_list) * 1);
	if (models)
		return (NULL);
	models = ft_lstnew((void *) NULL);
	return (models);
}

/*
 * This function get a a model from the models list
 */
t_model	*get_model(t_list *models_lst, int id)
{
	int	index;

	index = 0;
	while (models_lst != NULL)
	{
		if (index == id)
			return ((t_model *) models_lst->content);
		index++;
		models_lst = models_lst->next;
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
	t_list	*first_n;

	cur_n = ft_lstnew((void *) model);
	if (!cur_n)
		return ;
	first_n = ft_lstlast(models);
	ft_lstadd_back(&first_n, cur_n);
}
