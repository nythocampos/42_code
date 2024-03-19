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

static void	scale_model(t_list *model, float x, float y, float z)
{
	t_cor	scale;
	t_iaxes_updater	*a_updater;

 	a_updater = create_axes_updater();
	scale.x = x;
	scale.y = y;
	scale.z = z;
	process_lists(model, (void *) &scale, a_updater->scale_model);
	free(a_updater);
}

/*
 * This function apply a rotation to the object
 *
 * Args:
 * 	angles (t_cor): x, y, z angles to apply in the rotation
 * 	model (t_cor *): model faces
 */
static void	rotate_model(t_list *model, float x, float y, float z)
{
	float	*rot_z_m;
	float	*rot_x_m;
	float	*rot_y_m;
	t_imatrix_creator *mc;

	mc = create_matrix_creator();
	rot_x_m = mc->gen_rot_mtx_x(x);
	rot_y_m = mc->gen_rot_mtx_y(y);
	rot_z_m = mc->gen_rot_mtx_z(z);
	if (!rot_z_m || !rot_x_m || !rot_y_m)
		return ;
	if (x != 0)
		process_lists(model, (void *) rot_x_m, apply_matrix);
	if (y != 0)
		process_lists(model, (void *) rot_y_m, apply_matrix);
	if (z != 0)
		process_lists(model, (void *) rot_z_m, apply_matrix);
	free(rot_x_m);
	free(rot_y_m);
	free(rot_z_m);
	free(mc);
}

/*
 * This function moves the object to a new position.
 *
 * Args:
 * 	mode (t_face): the model to be moved.
 * 	n_pos(t_cor): new position where the model must be
 * 	pleaced.
 */
static void	move_model(t_list *model, float x, float y, float z)
{	
	t_cor		n_pos;
	t_iaxes_updater	*a_updater;

 	a_updater = create_axes_updater();
	n_pos.x = x;
	n_pos.y = y;
	n_pos.z = z;
	process_lists(model, (void *) &n_pos, a_updater->move_axes);
	free(a_updater);
}

/*
 * This function apply the projection perspective
 * to the {x,y,z} coordinates
 *
 * Args:
 * 	a (t_cor *): a pointer to the cor destination
 */
void	project_model(t_list *model)
{
	t_imatrix_creator	*pro_mtx;
	float			*mtx;

	pro_mtx = create_matrix_creator();
	mtx = pro_mtx->get_pro_mtx();
	process_lists(model, (void *) mtx, apply_matrix);
	free(pro_mtx);
}

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
