/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:50:30 by antcampo          #+#    #+#             */
/*   Updated: 2024/01/31 19:58:54 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	check_model(void *pts_lst)
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
}

static void	check_faces(t_face *faces_lst)
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
}

	// Load all data from the fdf file into a s_model struct considering
	// the position of the coordinate in the matrix imported.
	//
	// Check how many triangles are in the s_model
	//
	// Define list of t_world_coor considering how many triangles are
	// in the s_model.
	//
	// Fill the s_world_tri with the data considering the rotation
	// 
	// Define and fill the s_screen_tri using the s_projection_matrix
	//
	// Find a way to draw the lines of the triangles
int	main(void)
{
	t_mlx_data	mlx_data;
	t_list		*model_data;
	t_face		*model;
	
	// Load model
	model_data = load_model("./models/42.fdf");
	//model_data = load_model("./models/1.fdf");
	if(model_data == NULL)
		return (0);
	ft_printf("Model Loaded\n");

	// Check model
	ft_lstiter(model_data, check_model);

	// Project model
	model = build_faces(model_data);
	if(model == NULL)
		return (0);
	project_model(&model[0]);
	ft_printf("Model projected\n");

	// Check projection
	check_faces(&model[0]);
	//return (0);

	// Initialize window
	mlx_data.mlx = mlx_init();
	mlx_data.title = ft_strdup("FDF");
	mlx_data.width = WIDTH;
	mlx_data.hight = HEIGHT;
	set_window(&mlx_data);

	// set image / call frame_builder
	build_image(&mlx_data, &model[0]);
	// run window
	set_events(&mlx_data);
	mlx_loop(mlx_data.mlx);
	// free the mlx_data->mlx
	return (0);
}
