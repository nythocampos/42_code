
#include "../../fdf.h"

/*
 * This function initialize the matrix provided to 0
 */
void	initialize_m(float *m, int size)
{
	while (size > 0)
	{
		m[size] = 0;
		size--;
	}
}

void	apply_matrix(t_cor *src, void *mtx)
{
	float	w;
	float	*m;
	int	x;
	int	y;
	int	z;

	m = (float *) mtx;
	x = src->x * m[0] + src->y * m[1] + src->z * m[2] + m[3];
	y = src->x * m[4] + src->y * m[5] + src->z * m[6] + m[7];
	z = src->x * m[8] + src->y * m[9] + src->z * m[10] + m[11];
	w = x * m[12] + y * m[13] + z * m[14] + m[15];
	if (w != 0)
	{
		src->x = x / w;
		src->y = y / w;
		src->z = z / w;
	}
}

