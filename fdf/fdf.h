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

//TODO: check what is being imported twice

#include <fcntl.h>
#include <stdlib.h>
#include <math.h>

#include "libraries/libft_ulti/libft.h"
#include "libraries/mlx/mlx.h"

#include "structs.h"
#include "global_vars.h"

// Window module 
// Hooks
void	minimize_window(t_mlx_data *data);
void	end_program(t_mlx_data *data);
void	set_events(t_mlx_data *data);
void	set_window();

// Files module 
int	get_columns_num(char *line);
int	get_item_value(char *str, int end);
int	on_item(char *line, int index);
t_list	*load_model(char *file_name);
t_list	*load_terrain_model(int file_df);

// Models manager module
void	rotate_model(t_list *model, t_cor *angles);
void	process_faces(t_face *model, void *data, void (*f)(t_cor *, void *));
void	move_model(t_list *model, t_cor *n_pos, int mov_ty);
void	process_lists(t_list *node, void *data, void (*f)(t_cor *, void *));

//Graphic module 
void	build_image(t_mlx_data *mlx_data, t_face *faces_lst);
t_face	*build_faces(t_list *model);
t_cor	*build_triangle(t_list *cur_node, int col_i);
void	project_model(t_list *model);
void	magnify_model(t_list *model, t_cor *scale);

//Utils
void	apply_matrix(t_cor *src, void *m);
void	initialize_m(float *m, int size);

int	get_rows_num(t_list *model);
int	get_cols_num(t_cor *pts_list);

#endif
