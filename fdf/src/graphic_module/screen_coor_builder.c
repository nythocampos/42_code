

#include "../../fdf.h"

static int	get_cols_num(t_s_cor *pts_list)
{
	int	index;

	index = 0;
	while(pts_list[index].id != -1)
		index++;	
	return (index);
}

static int	get_rows_num(t_list *model)
{
	int	index;

	index = 0;
	while(model->next != NULL)
	{
		model = model->next;
		index++;
	}
	return (index);
}

t_face	*build_screen_coors(t_list *model)
{
	int	n_rows;
	int	n_cols;
	int	col_index;
	int	is_last_line;
	t_face	*faces_lst;

	col_index = 0;
	is_last_line = 0;
	n_rows = get_cols_num((t_s_cor *) model->content); 
	n_cols = get_rows_num(model);
	faces_lst = (t_face *)malloc(sizeof(t_face) * (n_cols * n_rows));
	if (!faces_lst)
		return (NULL);
	while(!is_last_line)
	{
		while (col_index <= n_cols)
		{
			build_face(model, &faces_lst[col_index], col_index);
			col_index++;
		}
		if(model->next == NULL)
			is_last_line = 1;
		else
			model = model->next;
	}
	return (faces_lst);

}

