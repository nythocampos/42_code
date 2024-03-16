/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:03:34 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/16 03:24:45 by antcampo         ###   ########.fr       */
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

void		refresh_window(t_state *state);

// Files module 
int			get_columns_num(char *line);
int			get_item_value(char *str, int end);
int			on_item(char *line, int index);
void		load_model(char *file_name,t_state *state);

// Models manager module
void		rotate_model(t_cor *cor, float x, float y, float z);
void		move_model(t_cor *cor, float x, float y, float z);
void		scale_model(t_cor *cor, float x, float y, float z);
void		project_model(t_cor *cor);
void		initialize_mod(t_cor *cor, int col_i, int row_i);

void		update_m_pos(t_state *state, int key);
void		update_m_s(t_state *state, int key);
void		update_m_r(t_state *state, int key);

// Graphic module 
void		set_pixel(t_img *img, int x, int y, int color);

// Data manager
t_state		*initialize_state(void);

// Utils
void		apply_matrix(t_cor *src, void *m);
void		initialize_m(float *m, int size);
int			get_rows_num(t_list *model);
int			get_cols_num(t_cor *pts_list);

#endif
