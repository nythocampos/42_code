/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:03:34 by antcampo          #+#    #+#             */
/*   Updated: 2024/01/31 20:08:42 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// defs ----------------------------------
#ifndef FDF_H
# define FDF_H

#define XK_Escape	0xff1b
#define COLOR	0x00FF0000

//TODO: check what is being imported twice

#include "libraries/mlx/mlx.h"
#include <fcntl.h>
#include <stdlib.h>
#include "libraries/libft_ulti/libft.h"
#include <math.h>
#include "structs.h"

// Hooks
void	minimize_window(t_mlx_data *data);
void	end_program(t_mlx_data *data);

// Window section
void	set_events(t_mlx_data *data);
void	set_window();

// Models manager section
int	get_columns_num(char *line);
int	get_item_value(char *str, int end);
int	on_item(char *line, int index);
t_list	*load_model(char *file_name);
t_list	*load_terrain_model(int file_df);

// Image builder section
void	build_image(t_mlx_data *mlx_data);

//utils
int	convert_3d_to_2d(int coordinate, int z_coordinate, int a);

#endif
