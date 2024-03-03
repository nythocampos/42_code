
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

/*static float	*gen_rot_mtx()
{
	float	*rot_mtx;

	rot_mtx = (float *) malloc (sizeof(float) * 6);
	if (!rot_mtx)
		return (NULL);
	rot_mtx[0] = (p_data.f_asp_rad * p_data.f_fov_rad);
	rot_mtx[1] = (p_data.f_fov_rad);
	rot_mtx[2] = (p_data.f_far / (p_data.f_far - p_data.f_near));
	rot_mtx[3] = ((-p_data.f_far * p_data.f_near) / 
		(p_data.f_far - p_data.f_near));
	rot_mtx[4] = 1.0;
	rot_mtx[5] = 0.0; 
	return (&rot_mtx[0]);
}*/

static float	*gen_prj_mtx()
{
	float		*prj_mtx;
	t_p_data	p_data;

	p_data.f_near = 0.1;
	p_data.f_far = 1000.0;
	p_data.f_fov = 90.0;
	p_data.f_asp_rad = ((float)WIDTH / (float)HEIGHT);
	p_data.f_fov_rad = 1.0 / tanf(p_data.f_fov * 0.5 * 3.14159 / 180.0);
	prj_mtx = (float *) malloc (sizeof(float) * 6);
	if (!prj_mtx)
		return (NULL);
	prj_mtx[0] = (p_data.f_asp_rad * p_data.f_fov_rad);
	prj_mtx[1] = (p_data.f_fov_rad);
	prj_mtx[2] = (p_data.f_far / (p_data.f_far - p_data.f_near));
	prj_mtx[3] = ((-p_data.f_far * p_data.f_near) / 
		(p_data.f_far - p_data.f_near));
	prj_mtx[4] = 1.0;
	prj_mtx[5] = 0.0; 
	return (&prj_mtx[0]);
}

static void	apply_matrix(t_cor *s_pts, t_cor *w_pts, float *m)
{
	float	w;

	s_pts->x = w_pts->x * m[0] + w_pts->y * 0 + w_pts->z * 0 + 0;
	s_pts->y = w_pts->x * 0 + w_pts->y * m[1] + w_pts->z * 0 + 0;
	s_pts->z = w_pts->x * 0 + w_pts->y * 0 + w_pts->z * m[2] + m[3];
	w = w_pts->x * 0 + w_pts->y * 0 + w_pts->z * m[4] + 0;
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
	t_cor *s_pts;
	t_cor	*w_pts;
	t_list	*temp_node;
	float	*prj_m;
	//float	*rot_m;

	face_size = find_face_size(cur_node, col_i);
	s_pts = (t_cor *) malloc(sizeof(t_cor) * face_size);
	if (!s_pts)
		return (NULL);
	prj_m = gen_prj_mtx();
	// current point
	w_pts =	(t_cor *) cur_node->content;
	apply_matrix(&s_pts[0], &w_pts[col_i], prj_m);
	apply_matrix(&s_pts[0], &w_pts[col_i], prj_m);
	s_pts[0].id = 0;

	// right point
	if (w_pts[col_i].id != -1)
	{
		apply_matrix(&s_pts[1], &w_pts[col_i + 1], prj_m);
		apply_matrix(&s_pts[1], &w_pts[col_i + 1], prj_m);
		s_pts[1].id = 0;
	}
	// down point
	if (cur_node->next != NULL)
	{
		temp_node = cur_node->next;
		w_pts = (t_cor *) temp_node->content;	
		apply_matrix(&s_pts[(face_size - 1)], &w_pts[col_i], prj_m);
		apply_matrix(&s_pts[(face_size - 1)], &w_pts[col_i], prj_m);
		s_pts[(face_size - 1)].id = 0;
	}
	s_pts[(face_size - 1)].id = -1;
	cur_node = NULL;
	w_pts = NULL;
	return (&s_pts[0]);
}

