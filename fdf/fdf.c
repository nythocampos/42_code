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

/*static void	check_model(struct s_element *model)
{
	struct s_element_node	*current_node;
	//struct s_coordinates	*coor;
	struct s_element_node	**nodes_list;
	int						index;

	current_node = NULL;
	nodes_list = model->shape;
	index = 0;
	ft_printf("MODEL DATA ------------------\n");
	//ft_printf("position X: %d, Y: %d, Z %d\n",
//		   	model->position->x, model->position->y, model->position->z);
	ft_printf("scale: %d\n", model->scale);
	while (nodes_list[index])
	{
		current_node = nodes_list[index];
		//coor = current_node->position;
		//ft_printf("X: %d, Y: %d, Z %d\n", coor->x, coor->y, coor->z);
		index++;
	}
}*/

int	main(void)
{
	struct s_mlx_data	*mlx_data;
	//TODO: Add a way to recive the file name
	initializate_window(mlx_data);
	// set image / call frame_builder
	build_frame(mlx_data);
	// run window
	mlx_loop(mlx_data->mlx_ptr);
	// free the mlx_data->mlx.ptr
	return (0);
}
