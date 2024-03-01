#include "../fdf.h"

#include <stdio.h>
static void	check_model(void *pts_list)
{
	int	index;
	t_w_cor	*w_cor;

	index = 1;
	w_cor =  (t_w_cor *) pts_list;
	while(w_cor[index].id <= 19)
	{
		printf("X:%.2f, Y:%.2f, Z:%.2f ---|ID:%d \n",
			w_cor[index].x,
			w_cor[index].y,
			w_cor[index].z,
			w_cor[index].id);
		index++;
	}
	ft_printf(" --- --- ---\n");
}
