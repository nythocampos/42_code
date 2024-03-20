/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models_rotator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:48:38 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/20 14:54:14 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static float	*gen_rot_mtx_z(float z_angle)
{
	float	*m_rot;

	m_rot = (float *) malloc (sizeof(float) * 16);
	if (!m_rot)
		return (NULL);
	initialize_m(m_rot, 16);
	m_rot[0] = cosf(z_angle);
	m_rot[1] = sinf(z_angle);
	m_rot[4] = -sinf(z_angle);
	m_rot[5] = cosf(z_angle);
	m_rot[10] = 1.0;
	m_rot[15] = 1.0;
	return (&m_rot[0]);
}

static float	*gen_rot_mtx_x(float x_angle)
{
	float	*m_rot;

	m_rot = (float *) malloc (sizeof(float) * 16);
	if (!m_rot)
		return (NULL);
	initialize_m(m_rot, 16);
	m_rot[0] = 1;
	m_rot[5] = cosf(x_angle);
	m_rot[6] = sinf(x_angle);
	m_rot[9] = -sinf(x_angle);
	m_rot[10] = cosf(x_angle);
	m_rot[15] = 1.0;
	return (&m_rot[0]);
}

static float	*gen_rot_mtx_y(float y_angle)
{
	float	*m_rot;

	m_rot = (float *) malloc (sizeof(float) * 16);
	if (!m_rot)
		return (NULL);
	initialize_m(m_rot, 16);
	m_rot[0] = cosf(y_angle);
	m_rot[2] = -sinf(y_angle);
	m_rot[5] = 1.0;
	m_rot[8] = sinf(y_angle);
	m_rot[10] = cosf(y_angle);
	m_rot[15] = 1.0;
	return (&m_rot[0]);
}

/*
 * This function apply a rotation to the object
 *
 * Args:
 * 	angles (t_cor): x, y, z angles to apply in the rotation
 * 	model (t_cor *): model faces
 */
void	rotate_model(t_cor *cor, float x, float y, float z)
{
	float	*rot_z_m;
	float	*rot_x_m;
	float	*rot_y_m;

	rot_x_m = gen_rot_mtx_x(x);
	rot_y_m = gen_rot_mtx_y(y);
	rot_z_m = gen_rot_mtx_z(z);
	if (!rot_z_m || !rot_x_m || !rot_y_m)
		return ;
	if (x != 0)
		apply_matrix(cor, rot_x_m);
	if (y != 0)	
		apply_matrix(cor, rot_y_m);
	if (z != 0)
		apply_matrix(cor, rot_z_m);
	free(rot_x_m);
	free(rot_y_m);
	free(rot_z_m);
}
