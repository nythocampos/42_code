
#include "../../fdf.h"

static int	find_face_size(t_list *cur_node, int col_i)
{
	int	face_size;
	t_w_cor	*w_pts;

	face_size = 3;
	w_pts = (t_w_cor *) cur_node->content;
	if (w_pts[col_i].id == -1)
		face_size = face_size - 1;
	if (cur_node->next == NULL)
		face_size = face_size - 1;
	return (face_size);
}

static int	project_coor(t_w_cor *w_pts, char axis)
{
	float		result;
	t_p_data	p_data;
	float		w_a;
	float		w_b;
	float		w;

	p_data.f_near = 0.1;
	p_data.f_far = 1000.0;
	p_data.f_fov = 90.0;
	p_data.f_asp_rad = ((float)WIDTH/(float)HEIGHT);
	//p_data.f_fov_rad = 1.0 / tanf(p_data.f_fov * 0.5 * 3.14159 / 180.0);
	p_data.f_fov_rad = 1.0 / tanf(p_data.f_fov * 0.5 / 180.0 * 3.14159);

	// apply rotation
	//w_pts->z = w_pts->z + 3.0;

	// apply rotation
	// isometric view
	/*float angle_rad_x = ROTATION_X * 3.14159 / 180;
	float angle_rad_y = ROTATION_Y * 3.14159 / 180;	

	float temp_y = w_pts->y;
	w_pts->y = cosf(angle_rad_x) * temp_y - sinf(angle_rad_x) * w_pts->z;
	w_pts->z = sinf(angle_rad_x) * temp_y + cosf(angle_rad_x) * w_pts->z;

	float temp_x = w_pts->x;
	w_pts->x = cosf(angle_rad_y) * temp_x - sinf(angle_rad_y) * w_pts->z;
	w_pts->z = sinf(angle_rad_y) * temp_x + cosf(angle_rad_y) * w_pts->z;*/

	// apply scaling
	//w_pts->y = w_pts->y + 1.0;
	//w_pts->x = w_pts->x * SCALE_X;
	//w_pts->y = w_pts->y * SCALE_Y;
	
	// apply projection
	w_a = (p_data.f_far / (p_data.f_far - p_data.f_near));
	w_b = ((-p_data.f_far * p_data.f_near) / 
		(p_data.f_far - p_data.f_near));
	w_pts->z = w_pts->z * (w_a + w_b);
	w = w_pts->z * 1.0;

	if (axis == 'x')
	{	
		result = w_pts->x * (p_data.f_asp_rad * p_data.f_fov_rad);
		if (w != 0)
			result = result / w;
		result = result + 1.0;
		result = result * (0.2 * (float) WIDTH);
	}
	else if (axis == 'y')
	{	
		result = (w_pts->y * p_data.f_fov_rad);
		if (w != 0)
			result = result / w;
		result = result + 1.0;
		result = result * (0.2 * (float) HEIGHT);
	}
	return ((int) result);
}

t_s_cor	*build_face(t_list *cur_node, int col_i)
{
	int	face_size;
	t_s_cor *s_pts;
	t_w_cor	*w_pts;
	t_list	*temp_node;

	face_size = find_face_size(cur_node, col_i);
	//ft_printf("face_size: %d\n", face_size);
	s_pts = (t_s_cor *) malloc(sizeof(t_s_cor) * face_size);
	if (!s_pts)
		return (NULL);
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
	
		s_pts[(face_size - 1)].x = project_coor(&w_pts[col_i], 'x');
		s_pts[(face_size - 1)].y = project_coor(&w_pts[col_i], 'y');
		s_pts[(face_size - 1)].id = 0;		
	}
	s_pts[(face_size - 1)].id = -1;
	cur_node = NULL;
	w_pts = NULL;
	return (&s_pts[0]);
}

