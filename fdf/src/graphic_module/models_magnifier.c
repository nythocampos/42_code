
#include "../../fdf.h"

static void	scale_model(t_cor *cor, void *scale)
{
	t_cor	*scl;

	scl = (t_cor *) scale;
	//cor->x = cor->x + 1;
	//cor->y = cor->y + 1;

	// Scale the projection
	//cor->x = cor->x * (0.1 * (float) WIDTH);
	//cor->y = cor->y * (0.1 * (float) HEIGHT);
	ft_printf("x: %d\n",(int)cor->x);
	ft_printf("y: %d\n",(int)cor->y);
	ft_printf("z: %d\n",(int)scl->z);
	// Scale the model
	cor->x = cor->x * scl->x;
	cor->y = cor->y * scl->y;
	cor->z = cor->z * scl->z;
}

void	magnify_model(t_list *model, t_cor *scale)
{
	process_lists(model, (void *) scale, scale_model);
}
