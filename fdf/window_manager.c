/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:20:09 by antcampo          #+#    #+#             */
/*   Updated: 2024/01/25 18:43:37 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	initialize_window(t_mlx_data *mlx_data)
{
	mlx_data->win_ptr = mlx_new_window(
		mlx_data->mlx_ptr,
		mlx_data->width,
		mlx_data->hight,
		mlx_data->title
		);
	
}

/*
 * This function sets everything nessary to run the window
 */
void	set_window(t_mlx_data *mlx_data)
{
	ft_printf("Building window...\n");	
	initialize_window(mlx_data);
	set_events(mlx_data);
	ft_printf("Window built...\n");
}

