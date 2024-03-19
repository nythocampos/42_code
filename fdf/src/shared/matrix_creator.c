
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

static float	*get_pro_mtx(void)
{
	float		*m_prj;
	t_p_data	p_data;
	int			m_size;

	m_size = 16;
	p_data.f_near = 0.1;
	p_data.f_far = 1000;
	p_data.f_fov = 120;
	p_data.f_asp_rad = ((float)WIDTH / (float)HEIGHT);
	p_data.f_fov_rad = 1 / tanf(p_data.f_fov * 0.5 * 3.14159 / 180.0);
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

t_imatrix_creator	*create_matrix_creator()
{
	t_imatrix_creator	*mc;

	mc = (t_imatrix_creator *) malloc(sizeof(t_imatrix_creator) * 1);
	if (!mc)
		return (NULL);
	mc->gen_rot_mtx_x = gen_rot_mtx_x;
	mc->gen_rot_mtx_y = gen_rot_mtx_y;
	mc->gen_rot_mtx_z = gen_rot_mtx_z;
	mc->get_pro_mtx = get_pro_mtx;
	return (mc);
}
