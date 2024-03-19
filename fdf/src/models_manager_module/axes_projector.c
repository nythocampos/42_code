
#include "../../fdf.h"

void	project_axes(t_cor *cor, float *pro_mtx)
{
	apply_matrix(cor, (void *) pro_mtx);
}

void	scale_axes_projection(t_cor *cor, float x, float y, float z)
{
	cor->x = cor->x * x;
	cor->y = cor->y * y;
	cor->z = cor->z * z;
}
