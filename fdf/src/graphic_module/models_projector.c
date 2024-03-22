/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models_projector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:42:20 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/20 14:57:15 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

float	*gen_prj_mtx(void)
{
	float		*m_prj;
	t_p_data	p_data;
	int			m_size;

	m_size = 16;
	p_data.f_near = 0.1;
	p_data.f_far = 1000;
	p_data.f_fov = 90;
	p_data.f_asp_rad = ((float)HEIGHT / (float)WIDTH);
	p_data.f_fov_rad = 1 / tanf(p_data.f_fov * 0.5 / 180.0* 3.14159);
	m_prj = (float *) malloc (sizeof(float) * m_size);
	if (!m_prj)
		return (NULL);
	initialize_m(m_prj, m_size);
	m_prj[0] = (p_data.f_asp_rad * p_data.f_fov_rad);
	m_prj[5] = (p_data.f_fov_rad);
	m_prj[10] = (p_data.f_far / (p_data.f_far - p_data.f_near));
	m_prj[11] = ((-p_data.f_far * p_data.f_near)
			/ (p_data.f_far - p_data.f_near));
	m_prj[14] = 1.0;
	m_prj[15] = 0.0;
	return (&m_prj[0]);
}

/*
 * This function apply the projection perspective
 * to the {x,y,z} coordinates
 *
 * Args:
 * 	a (t_cor *): a pointer to the cor destination
 */
void	project_model(t_cor *cor)
{
	float	*prj_m;

	prj_m = gen_prj_mtx();
	if (!prj_m)
		return ;
	apply_matrix(cor, prj_m);
	free(prj_m);
}
