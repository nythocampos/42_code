
#include "../../fdf.h"

void	scale_axes(t_cor *cor, float x, float y, float z)
{
	cor->x = cor->x * x;
	cor->y = cor->y * y;
	cor->z = cor->z * z;
}

void	move_axes(t_cor *cor, float x, float y, float z)
{
	cor->x = cor->x + x;
	cor->y = cor->y + y;
	cor->z = cor->z + z;
}

void	rotate_axes(t_cor *cor, float *rot_mtx)
{
	apply_matrix(cor, (void *) rot_mtx);
}
