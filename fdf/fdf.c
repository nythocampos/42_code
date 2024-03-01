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

#include <stdio.h>
/*static void	check_model(void *pts_lst)
{
	int	index;
	t_w_cor	*w_cor;

	index = 1;
	w_cor =  (t_w_cor *) pts_lst;
	while(w_cor[index - 1].id != -1)
	{
		printf("X:%d, Y:%d, Z:%d ---|ID:%d \n",
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
	int	index;
	int	end_faces;
	t_s_cor	*points;

	index = 0;
	end_faces = 0;
	while(end_faces == 0)
	{
		points = faces_lst[index].points;
		printf("Face ID: %d\n", faces_lst[index].id);

		printf("X:%.2f, ", points[0].x);
		printf("Y:%.2f, ", points[0].y);
		printf("ID:%d \n", points[0].id);

		ft_printf(" ---\n");

		printf("X:%.2f, ", points[1].x);
		printf("Y:%.2f, ", points[1].y);
		printf("ID:%d \n", points[1].id);

		ft_printf(" ---\n");

		printf("X:%.2f, ", points[2].x);
		printf("Y:%.2f, ", points[2].y);
		printf("ID:%d \n", points[2].id);
	
		ft_printf("||||||||||||||||||||||||\n");
		index++;
		if (faces_lst[index].id == -1)
			end_faces = 1;
	}
	ft_printf(" --- --- ---\n");
}*/

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
	t_list		*model;
	t_face		*faces_list;
	
	// Load model
	model = load_model("./models/42.fdf");
	if(model == NULL)
		return (0);
	ft_printf("Model Loaded\n");

	// Check model
	//ft_lstiter(model, check_model);

	// Project model
	faces_list = build_screen_coors(model);
	if(faces_list == NULL)
		return (0);
	ft_printf("Model projected\n");

	// Check projection
	//check_faces(&faces_list[0]);
	//return (0);

	// Initialize window
	mlx_data.mlx = mlx_init();
	mlx_data.title = ft_strdup("FDF");
	mlx_data.width = WIDTH;
	mlx_data.hight = HEIGHT;
	set_window(&mlx_data);

	// set image / call frame_builder
	build_image(&mlx_data, &faces_list[0]);
	// run window
	set_events(&mlx_data);
	mlx_loop(mlx_data.mlx);
	// free the mlx_data->mlx
	return (0);
}
