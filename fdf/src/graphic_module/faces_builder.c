
#include "../../fdf.h"

static int	find_face_size(t_list *cur_node, int col_i)
{
	int	face_size;
	t_w_cor	*w_pts;

	face_size = 3;
	w_pts = (t_w_cor *) cur_node->content;
	if (w_pts[col_i].id == -1)
		face_size--;
	if (cur_node->next == NULL)
		face_size--;
	return (face_size);
}

float	project_coor(t_w_cor *w_pts, char axis)
{
	float		result;
	t_p_data	p_data;
	float		z_a;
	float		z_b;

	p_data.f_near = 0.1;
	p_data.f_far = 1000.0;
	p_data.f_fov = 90.0;
	p_data.f_asp_rad = (HEIGHT/WIDTH);
	p_data.f_fov_rad = (1/tan(p_data.f_fov * 0.5 / 180 * 3.14159));
	// apply rotation
	w_pts->z = w_pts->z + ROTATION;
	// apply projection
	z_a = (p_data.f_far / (p_data.f_far - p_data.f_near));
	z_b = ((-p_data.f_far * p_data.f_near) / 
		(p_data.f_far - p_data.f_near));
	w_pts->z = w_pts->z * (z_a + z_b);
	if (axis == 'x')
	{	
		result = w_pts->x * (p_data.f_asp_rad * p_data.f_fov_rad);
		result = result / w_pts->z;
		// apply scale
		result = result + SCALE;	
		result = result * (0.5*WIDTH);
	}
	else if (axis == 'y')
	{	
		result = w_pts->y * p_data.f_fov_rad;
		result = result / w_pts->z;
		// apply scale
		result = result + SCALE;
		result = result * (0.5*HEIGHT);
	}
	return (result);
}

void	build_face(t_list *cur_node, t_face *faces_list, int col_i)
{
	int	face_size;
	t_s_cor *s_pts;
	t_w_cor	*w_pts;
	t_list	*temp_node;

	face_size = find_face_size(cur_node, col_i);
	s_pts = (t_s_cor *) malloc(sizeof(t_s_cor) * face_size + 1);
	if (!s_pts)
		return;
	// current point
	w_pts =	(t_w_cor *) cur_node->content;
	s_pts[0].x = project_coor(&w_pts[col_i], 'x');
	s_pts[0].y = project_coor(&w_pts[col_i], 'y');
	s_pts[0].id = 0;
	// right point
	if (w_pts[col_i].id != -1)
	{
		s_pts[1].x = project_coor(&w_pts[col_i + 1], 'x');
		s_pts[1].y = project_coor(&w_pts[col_i + 1], 'y');
		s_pts[1].id = 0;
	}
	// down point
	if (cur_node->next != NULL)
	{
		temp_node = cur_node->next;
		w_pts = (t_w_cor *) temp_node->content;
		s_pts[2].x = project_coor(&w_pts[col_i], 'x');
		s_pts[2].y = project_coor(&w_pts[col_i], 'y');
		s_pts[2].id = 0;
	}
	s_pts[face_size - 1].id = -1;
	faces_list->points = &s_pts[0];
	s_pts = NULL;
	cur_node = NULL;
	w_pts = NULL;
}

