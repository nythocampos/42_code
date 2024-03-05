
#include "../fdf.h"

/*static void	check_model(void *pts_lst)
{
	int	index;
	t_cor	*w_cor;

	return;
	index = 0;
	w_cor =  (t_cor *) pts_lst;
	while(w_cor[index - 1].id != -1)
	{
		ft_printf("X:%d, Y:%d, Z:%d ---|ID:%d \n",
			w_cor[index].x,
			w_cor[index].y,
			w_cor[index].z,
			w_cor[index].id);
		index++;
	}
	ft_printf(" --- --- ---\n");
}*/

/*static void	check_faces(t_face *faces_lst)
{
	int	faces_i;
	int	pts_i;
	int	end_faces;
	int	end_pts;
	t_cor	*points;

	return;
	faces_i = 0;
	pts_i = 0;
	end_faces = 0;
	end_pts = 0;
	while(end_faces == 0)
	{
		ft_printf("Face ID: %d\n", faces_lst[faces_i].id);	
		points = faces_lst[faces_i].points;
		while (end_pts == 0)
		{
			//break;
			ft_printf("X:%d, ",(int)points[pts_i].x);
			ft_printf("Y:%d, ",(int)points[pts_i].y);
			ft_printf("ID:%d \n", points[pts_i].id);
			ft_printf(" ---\n");
			if (points[pts_i].id == -1)
				end_pts = 1;
			pts_i++;
		}	
		ft_printf("||||||||||||||||||||||||\n");
		if (faces_lst[faces_i].id == -1)
			end_faces = 1;
		end_pts = 0;
		pts_i = 0;
		faces_i++;
	}
	ft_printf(" --- --- ---\n");
}*/

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
