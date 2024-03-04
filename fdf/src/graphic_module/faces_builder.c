

#include "../../fdf.h"

//TODO: MOVE THIS TO UTILS??
static int	get_cols_num(t_cor *pts_list)
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

//TODO: MOVE THIS TO UTILS??
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

/*
 * This function builds the faces TODO: considering
 * the type of face needed.
 *
 * Args:
 * 	model (t_list *): a list of nodes, every node contain
 * 	a list of coordinates (t_cor).
 * Return:
 * 	faces_list (t_face *): the list of faces generated
 */
t_face	*build_faces(t_list *model)
{
	int	n_rows;
	int	n_cols;
	int	col_i;
	int	is_last_line;
	t_face	*faces_lst;
	int	index;

	col_i = 0;
	index = 0;
	is_last_line = 0;
	n_rows = get_rows_num(model); 
	n_cols = get_cols_num((t_cor *) model->content);
	faces_lst = (t_face *) malloc(sizeof(t_face) * (n_cols * n_rows));
	if (!faces_lst)
		return (NULL);
	while(is_last_line == 0)
	{
		while (col_i <= (n_cols - 1))
		{
			faces_lst[index].points = build_triangle(
				model,
				col_i);
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

