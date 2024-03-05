
#include "../../fdf.h"

int	get_cols_num(t_cor *pts_list)
{
	int	index;
	int	n_cols;

	index = 0;
	n_cols = 1;
	while(pts_list[index].id != -1)
	{
		index++;
		n_cols++;
	}
	return (n_cols);
}

int	get_rows_num(t_list *model)
{
	int	index;

	index = 1;
	while(model->next != NULL)
	{
		model = model->next;
		index++;
	}
	return (index);
}



