/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models_updater.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:35:08 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/18 19:32:16 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

t_imodel_updater	*create_model_updater()
{
	t_imodel_updater	*m_updater;

	m_updater = (t_imodel_updater *) malloc(sizeof(t_imodel_updater) * 1);
	if (!m_updater)
		return (NULL);
	m_updater->scale_model = &scale_model;
	m_updater->rotate_model = &rotate_model;
	m_updater->move_model = &move_model;
	m_updater->project_model = &project_model;
	return (m_updater);
}
