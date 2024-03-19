
#include "../../fdf.h"

t_iaxes_updater	*create_axes_updater()
{
	t_iaxes_updater	*a_updater;

	a_updater = (t_iaxes_updater *) malloc(sizeof(t_iaxes_updater) * 1);
	if (!a_updater)
		return (NULL);
	a_updater->scale_axes = &scale_axes;
	a_updater->rotate_axes = &rotate_axes;
	a_updater->move_axes = &move_to_pos;
	a_updater->project_axes = &project_axes;
	a_updater->scale_projection_axes = &scale_projection_axes;
	return (a_updater);
}
