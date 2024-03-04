
#include "../../fdf.h"

static void	scale_model(t_cor *cor, void *scale)
{
	float	*scl;

	scl = (float *) scale;
	cor->x = cor->x + 1.0;
	cor->y = cor->y + 1.0;

	//cor->x = cor->x * *scl * (float) WIDTH;
	cor->x = cor->x * *scl;
	//cor->y = cor->y * *scl * (float) HEIGHT;
	cor->y = cor->y * *scl;
}

void	magnify_model(t_face *model, float *scale)
{
	process_model(model, (void *) scale, scale_model);
}
