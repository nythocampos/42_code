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
static void	check_model(void *pts_lst)
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
	t_list		*model;
	
	// Load model
	model = load_model("./models/42.fdf");
	if(model == NULL)
		return (0);
	ft_printf("Model Loaded\n");

	// Check model
	ft_lstiter(model, check_model);
	return (0);
	// set image / call frame_builder
	build_image(&mlx_data);

	mlx_data.mlx = mlx_init();
	mlx_data.title = ft_strdup("FDF");
	mlx_data.width = 1300;
	mlx_data.hight = 700;
	set_window(&mlx_data);

	// run window
	set_events(&mlx_data);
	//mlx_loop(mlx_data.mlx);
	// free the mlx_data->mlx
	return (0);
}
