/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:03:34 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/07 21:31:03 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// defs ----------------------------------
#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# include "libraries/libft_ulti/libft.h"
# include "libraries/mlx/mlx.h"

# include "structs.h"
# include "macros.h"

// Window module 
// Hooks
void		end_program(t_state *state);
void		set_events(t_state *data);
void		set_window(t_mlx_data *mlx_data, char *title);

// Files module 
int			get_columns_num(char *line);
int			get_item_value(char *str, int end);
int			on_item(char *line, int index);
t_list		*load_terrain_model(int file_df);

// Models manager module
void		rotate_model(t_list *model, t_cor *angles);
void		process_faces(
				t_face *model, void *data, void (*f)(t_cor *, void *));
void		move_model(t_list *model, t_cor *n_pos, int mov_ty);
void		process_lists(t_list *node, void *data, void (*f)(t_cor *, void *));
void		initialize_mod(t_list *model_data, int model_num);
t_models	*import_models(int n_mod, char **argv);

// Graphic module 
void		build_image(t_mlx_data *mlx_data, t_face *faces_lst);
t_face		*build_faces(t_list *node);
void		build_triangles(
				t_list *node, t_face *faces, int n_cols, int *index);
void		project_model(t_list *model);
void		magnify_model(t_list *model, t_cor *scale);
void		draw_face(t_mlx_data *mlx_data, t_cor *points);
void		set_pixel(t_img *img, int x, int y, int color);

// Data manager
t_state		*initialize_state(int n_mod, char **argv);

// Utils
void		apply_matrix(t_cor *src, void *m);
void		initialize_m(float *m, int size);
int			get_rows_num(t_list *model);
int			get_cols_num(t_cor *pts_list);

#endif
