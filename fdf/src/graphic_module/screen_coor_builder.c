

#include "../../fdf.h"

static int	get_cols_num(t_w_cor *pts_list)
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

static int	get_rows_num(t_list *model)
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

t_face	*build_screen_coors(t_list *model)
{
	int	n_rows;
	int	n_cols;
	int	col_i;
	int	is_last_line;
	t_face	*faces_lst;
	int	index;

	//t_s_cor	*temp_pts;

	col_i = 0;
	index = 0;
	is_last_line = 0;
	n_rows = get_rows_num(model); 
	n_cols = get_cols_num((t_w_cor *) model->content);
	faces_lst = (t_face *) malloc(sizeof(t_face) * (n_cols * n_rows));
	if (!faces_lst)
		return (NULL);
	while(is_last_line == 0)
	{
		while (col_i <= (n_cols - 1))
		{
			faces_lst[index].points = build_face(model, col_i);
			faces_lst[index].id = index;
			col_i++;
			index++;
		}
		col_i = 0;
		if(model->next == NULL)
			is_last_line = 1;
		else
			model = model->next;
	}
	faces_lst[(n_cols * n_rows) - 1].id = -1;
	return (&faces_lst[0]);
}

