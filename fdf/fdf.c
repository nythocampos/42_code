/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:50:30 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/05 14:05:39 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



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
	t_ctl		ctl;

	t_cor angles;
	t_cor scl;
	t_cor n_pos;
	//ctl.ang = &angles;
	//ctl.scl = &scl;
	//ctl.n_pos = &n_pos;

	// Initialize window
	mlx_data.mlx = mlx_init();
	mlx_data.title = ft_strdup("FDF");
	mlx_data.width = WIDTH;
	mlx_data.hight = HEIGHT;
	mlx_data.ctl = &ctl;
	set_window(&mlx_data);
	
	// Load model
	model_data = load_model("./models/42.fdf");
	//model_data = load_model("./models/1.fdf");
	if(model_data == NULL)
		return (0);
	ft_printf("Model Loaded\n");
	scl.x = 1; // 120
	scl.y = 0.2; // 120
	scl.z = 1; // 120
	magnify_model(model_data, &scl);
	// ROTATE
	angles.x = 1;//35 !!! ERROR 15
	angles.y = 0.7;//45  !!! ERROR 15
	angles.z = 0.1;//15 !!! WORKING A LITTLE
	rotate_model(model_data, &angles);
	// SCALE
	scl.x = 90; // 120
	scl.y = 90; // 120
	scl.z = 0.1; // 120
	magnify_model(model_data, &scl);
	// CORRECT POS
	n_pos.x = 0; //500 // 100 /-50 -50 -50
	n_pos.y = 0; //500 /2000
	n_pos.z = 0;
	move_model(model_data, &n_pos, 1);
	n_pos.x = 100; //500 // 100
	n_pos.y = 200; //500 /2000
	n_pos.z = 1;
	move_model(model_data, &n_pos, 1);

	// SCALE
	//magnify_model(model_data, &scl);

	// MOVE
	//move_model(model_data, &n_pos, 1);

	// PROJECT
	project_model(model_data);

	//magnify_model(model_data, &scl);

	model = build_faces(model_data);
	if(model == NULL)
		return (0);

	build_image(&mlx_data, &model[0]);
	set_events(&mlx_data);
	mlx_loop(mlx_data.mlx);

	// free the mlx_data->mlx
	// free model_data t_list and t_cor inside
	// free model t_faces and t_cor inside
	return (0);
}
