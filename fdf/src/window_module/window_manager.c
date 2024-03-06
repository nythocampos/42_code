/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:20:09 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/05 13:25:49 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static void	initialize_window(t_mlx_data *mlx_data, char *title)
{
	mlx_data->win = mlx_new_window(
			mlx_data->mlx,
			WIDTH,
			HEIGHT,
			title
			);
}

/*
 * This function sets everything nessary to run the window
 */
void	set_window(t_mlx_data *mlx_data, char *title)
{
	initialize_window(mlx_data, title);
}
