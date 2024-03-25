/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:03:34 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/25 15:05:58 by antcampo         ###   ########.fr       */
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
# include "interfaces.h"

// Window module 
// Hooks
void				end_program(t_state *state);
void				set_events(t_state *data);
void				initialize_img(t_mlx_data *mlx_data, char *title);

// Files module 
/*void		get_columns_num(char *line, int	*cols_n);
int		get_item_value(char *str, int end);
int		on_item(char *line, int index);*/
t_list				*load_terrain_model(int file_df, t_state *state);

// Models manager module
void				process_lists(
						t_list *node, void *data, void (*f)(t_cor *, void *));
t_models			*import_model(char **argv, t_state *state);
// Graphic module 
void				set_pixel(t_img *img, int x, int y, int color);
void				build_triangles(
						t_list *node, int n_cols, int *row, t_state *state);

void				build_image(t_mlx_data *mlx_data);
void				build_faces(t_list *node, t_state *state);
void				draw_line(t_mlx_data *mlx, t_ptn *a, t_ptn *b);
void				project_model(t_cor *cor);
void				move_model(t_cor *cor, float x, float y, float z);
void				rotate_model(t_cor *cor, float x, float y, float z);
void				scale_model(t_cor *cor, float x, float y, float z);
void				scale_projection(t_cor *cor, float x, float y);

void				draw_vector(t_cor *a, t_cor *b, t_state *state);

// Data manager
t_state				*initialize_state(char **argv);

// Utils
void				apply_matrix(t_cor *src, void *m);
void				initialize_m(float *m, int size);
int					get_rows_num(t_list *model);
int					get_cols_num(t_cor *pts_list);
void				is_garbage(char *tmp_l);
void				get_largest_item(float item, t_state *state);
void				get_longest_line(int cur_line_len, t_state *state);

// interfaces
t_data_extractor	*create_data_extractor(void);
#endif
