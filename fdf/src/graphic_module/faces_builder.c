
#include "../../fdf.h"

static int	find_face_size(t_list *cur_node, int col_i)
{
	int	face_size;
	t_cor	*w_pts;

	face_size = 3;
	w_pts = (t_cor *) cur_node->content;
	if (w_pts[col_i].id == -1)
		face_size = face_size - 1;
	if (cur_node->next == NULL)
		face_size = face_size - 1;
	return (face_size);
}

static void	initialize_m(float *m,int size)
{
	while (size > 0)
	{
		m[size] = 0;
		size--;
	}
}

static float	*gen_rot_mtx_z(float elip)
{
	float	*m_rot;
	float	f_theta;
	int	m_size;

	f_theta = 1.0 + elip;
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

static float	*gen_rot_mtx_x(float elip)
{
	float	*m_rot;
	float	f_theta;
	int	m_size;

	f_theta = 1.0 + elip;
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

static float	*gen_prj_mtx()
{
	float		*m_prj;
	t_p_data	p_data;
	int		m_size;

	m_size = 16;
	p_data.f_near = 0.1;
	p_data.f_far = 1000.0;
	p_data.f_fov = 90.0;
	p_data.f_asp_rad = ((float)WIDTH / (float)HEIGHT);
	p_data.f_fov_rad = 1.0 / tanf(p_data.f_fov * 0.5 * 3.14159 / 180.0);
	m_prj = (float *) malloc (sizeof(float) * m_size);
	if (!m_prj)
		return (NULL);
	initialize_m(m_prj, m_size);
	m_prj[0] = (p_data.f_asp_rad * p_data.f_fov_rad);
	m_prj[5] = (p_data.f_fov_rad);
	m_prj[10] = (p_data.f_far / (p_data.f_far - p_data.f_near));
	m_prj[11] = ((-p_data.f_far * p_data.f_near) / 
		(p_data.f_far - p_data.f_near));
	m_prj[14] = 1.0;
	m_prj[15] = 0.0; 
	return (&m_prj[0]);
}

static void	apply_matrix(t_cor *s_pts, t_cor *w_pts, float *m)
{
	float	w;

	s_pts->x = w_pts->x * m[0] + w_pts->y * m[1] + w_pts->z * m[2] + m[3];
	s_pts->y = w_pts->x * m[4] + w_pts->y * m[5] + w_pts->z * m[6] + m[7];
	s_pts->z = w_pts->x * m[8] + w_pts->y * m[9] + w_pts->z * m[10] + m[11];
	w = w_pts->x * m[12] + w_pts->y * m[13] + w_pts->z * m[14] + m[15];
	if (w != 0)
	{
		s_pts->x = s_pts->x / w;
		s_pts->y = s_pts->y / w;
		s_pts->z = s_pts->z / w;
	}
}

t_cor	*build_face(t_list *cur_node, int col_i)
{
	int	face_size;
	t_cor	*s_pts;
	t_cor	*tmp_p;
	t_cor	*w_pts;
	t_list	*temp_node;
	float	*prj_m;
	float	*rot_z_m;
	float	*rot_x_m;
	int	z_offs;

	z_offs = 3;
	face_size = find_face_size(cur_node, col_i);
	rot_z_m = gen_rot_mtx_z(75);
	rot_x_m = gen_rot_mtx_x(5);
	prj_m = gen_prj_mtx();
	tmp_p = (t_cor *) malloc(sizeof(t_cor) * face_size);
	if (!tmp_p)
		return (NULL);
	s_pts = (t_cor *) malloc(sizeof(t_cor) * face_size);
	if (!s_pts)
		return (NULL);
	// current point
	w_pts =	(t_cor *) cur_node->content;

	w_pts[col_i].z = w_pts[col_i].z + z_offs;
	apply_matrix(&tmp_p[0], &w_pts[col_i], rot_z_m);
	apply_matrix(&s_pts[0], &tmp_p[col_i], rot_x_m);

	apply_matrix(&tmp_p[0], &s_pts[col_i], prj_m);
	tmp_p[0].id = 0;

	tmp_p[0].x = tmp_p[0].x + 1;
	tmp_p[0].y = tmp_p[0].y + 1;

	tmp_p[0].x = tmp_p[0].x * SCALE_X * (float) WIDTH;
	tmp_p[0].y = tmp_p[0].y * SCALE_Y * (float) HEIGHT;

	// right point
	if (w_pts[col_i].id != -1)
	{

		w_pts[col_i].z = w_pts[col_i].z + z_offs;
		apply_matrix(&tmp_p[1], &w_pts[col_i + 1], rot_z_m);
		apply_matrix(&s_pts[1], &tmp_p[col_i + 1], rot_x_m);

		apply_matrix(&tmp_p[1], &s_pts[col_i + 1], prj_m);
		tmp_p[1].id = 0;

		tmp_p[1].x = tmp_p[1].x + 1;
		tmp_p[1].y = tmp_p[1].y + 1;
		tmp_p[1].x = tmp_p[1].x * SCALE_X * (float) WIDTH;
		tmp_p[1].y = tmp_p[1].y * SCALE_Y * (float) HEIGHT;
	}
	// down point
	if (cur_node->next != NULL)
	{
		temp_node = cur_node->next;
		w_pts = (t_cor *) temp_node->content;

		w_pts[(face_size - 1)].z = w_pts[(face_size - 1)].z + z_offs;
		apply_matrix(&tmp_p[(face_size - 1)], &w_pts[col_i], rot_z_m);
		apply_matrix(&s_pts[(face_size - 1)], &tmp_p[col_i], rot_x_m);
		apply_matrix(&tmp_p[(face_size - 1)], &s_pts[col_i], prj_m);

		tmp_p[(face_size - 1)].id = 0;

		tmp_p[(face_size - 1)].x = tmp_p[(face_size - 1)].x + 1;
		tmp_p[(face_size - 1)].y = tmp_p[(face_size - 1)].y + 1;
		tmp_p[(face_size-1)].x = tmp_p[(face_size-1)].x * SCALE_X * (float) WIDTH;
		tmp_p[(face_size-1)].y = tmp_p[(face_size-1)].y * SCALE_Y * (float) HEIGHT;

	}
	tmp_p[(face_size - 1)].id = -1;
	cur_node = NULL;
	w_pts = NULL;
	return (&tmp_p[0]);
}

