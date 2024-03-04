
#include "../../fdf.h"

float	*gen_rot_mtx_z(float z_angle)
{
	float	*m_rot;
	float	f_theta;
	int	m_size;

	f_theta = 1.0 + z_angle;
	m_size = 16;
	m_rot = (float *) malloc (sizeof(float) * m_size);
	if (!m_rot)
		return (NULL);
	initialize_m(m_rot, m_size);
	m_rot[0] = cosf(f_theta);
	m_rot[4] = sinf(f_theta);
	m_rot[1] = -sinf(f_theta);
	m_rot[5] = cosf(f_theta);
	m_rot[10] = 1.0;
	m_rot[15] = 1.0; 
	return (&m_rot[0]);
}

float	*gen_rot_mtx_x(float x_angle)
{
	float	*m_rot;
	float	f_theta;
	int	m_size;

	f_theta = 1.0 + x_angle;
	m_size = 16;
	m_rot = (float *) malloc (sizeof(float) * m_size);
	if (!m_rot)
		return (NULL);
	initialize_m(m_rot, m_size);
	m_rot[0] = 1;
	m_rot[5] = cosf(f_theta * 0.5);
	m_rot[9] = sinf(f_theta * 0.5);
	m_rot[6] = -sinf(f_theta * 0.5);
	m_rot[10] = cosf(f_theta * 0.5);
	m_rot[15] = 1.0; 
	return (&m_rot[0]);
}

/*
 * This function apply a rotation to the object
 *
 * Args:
 * 	angles (t_cor): x, y, z angles to apply in the rotation
 * 	model (t_cor *): 3D model coordinates list
 */
void	rotate_model(t_cor *model, t_cor *angles)
{
	float	*rot_z_m;
	float	*rot_x_m;
	int	is_end;
	int	index;

	rot_z_m = gen_rot_mtx_z(angles->z);
	rot_x_m = gen_rot_mtx_x(angles->x);
	index = 0;
	is_end = 0;
	// Apply the angles rotation to every
	// point of the model use a while(is_end)
	while (is_end == 0)
	{
		apply_matrix(&model[0], rot_z_m);	
		apply_matrix(&model[0], rot_x_m);
		if (model[index].id == -1)
			is_end = 1;
		index++;
	}

	free(rot_z_m);
	free(rot_x_m);
}

