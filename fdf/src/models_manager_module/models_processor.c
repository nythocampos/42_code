
#include "../../fdf.h"

/*
 * This function go through every point in the model
 * applying the function f on all them.
 *
 * Args:
 * 	points (t_cor *): the points in the face
 * 	f (function): the function to apply
 */
static void	update_cor(t_cor *points, void *data, void (*f)(t_cor *, void *))
{
	int	pts_i;
	int	end_pts;

	pts_i = 0;
	end_pts = 0;
	while(end_pts == 0)
	{
		f(&points[pts_i], data);
		if (points[pts_i].id == -1)
			end_pts = 1;
		pts_i++;
	}
}

/* 
 * This function go through the faces 
 *
 * Args:
 * 	model (t_face *): all faces in the model
 * 	data (void *): data used by f
 * 	f (function): the function to apply in the model
 * */
void	process_model(t_face *model, void *data, void (*f)(t_cor *, void *))
{
	int	faces_i;
	int	end_faces;
	t_cor	*points;

	faces_i = 0;
	end_faces = 0;
	while(end_faces == 0)
	{
		points = model[faces_i].points;
		update_cor(points, data, f);
		if (model[faces_i].id == -1)
			end_faces = 1;
		faces_i++;
	}
}
