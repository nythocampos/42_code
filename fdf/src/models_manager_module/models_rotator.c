
#include "../../fdf.h"

static float	*gen_rot_mtx_z(float z_angle)
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

static float	*gen_rot_mtx_x(float x_angle)
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

static float	*gen_rot_mtx_y(float y_angle)
{
	float	*m_rot;
	float	f_theta;
	int	m_size;

	f_theta = 1.0 + y_angle;
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
 * 	model (t_cor *): model faces
 */
void	rotate_model(t_face *model, t_cor *angles)
{
	float	*rot_z_m;
	float	*rot_x_m;
	float	*rot_y_m;

	rot_z_m = gen_rot_mtx_z(angles->z);
	rot_x_m = gen_rot_mtx_x(angles->x);
	rot_y_m = gen_rot_mtx_y(angles->y);
	if (!rot_z_m || !rot_x_m || !rot_y_m)
		return;	
	if (angles->z != 0)
		process_model(model, (void *) rot_z_m, apply_matrix);
	if (angles->x != 0)
		process_model(model, (void *) rot_x_m, apply_matrix);
	if (angles->y != 0)
		process_model(model, (void *) rot_y_m, apply_matrix);
	free(rot_z_m);
	free(rot_x_m);
	free(rot_y_m);
}

