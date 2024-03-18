/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:03:34 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/18 19:45:03 by antcampo         ###   ########.fr       */
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
void		end_program();
void		set_events(t_state *data);
void		set_window(t_mlx_data *mlx_data, char *title);
void		refresh_window(t_state *state);
t_mlx_data	*create_mlx_data(void);
void		clean_mlx_data(t_mlx_data *mlx_data);
// Files module
t_ifile_loader	*create_file_loader();
int			get_item_value(char *str, int end);
int			on_item(char *line, int index);

// Models manager module
// TODO: implement project, rotate, scale and move from updater

void	set_model(t_list *models, t_model *model);
t_list		*create_models_list();
void		project_model(t_list *model);
void		rotate_model(t_list *model, float x, float y, float z);
void		scale_model(t_list *model, float x, float y, float z);
void		move_model(t_list *model, float x, float y, float z);
void		process_lists(t_list *node, void *data, void (*f)(t_cor *, void *));
t_imodel_collector	*create_fdf_collector();
t_model				*get_model(t_list *models_lst, int id);
t_imodel_updater	*create_model_updater();

// what is this????
void		update_m_pos(t_state *state, int key);
void		update_m_s(t_state *state, int key);
void		update_m_r(t_state *state, int key);
// Graphic module 

void				set_pixel(t_img *img, int x, int y, int color);
t_ipixels_writer	*create_pixels_writer();
void				draw_line(t_mlx_data *mlx, t_cor *a, t_cor *b);
t_imodel_printer	*create_model_printer();
t_ipixels_writer	*create_pixels_writer();
//	Shared 
void		apply_matrix(t_cor *src, void *m);
void		initialize_m(float *m, int size);
int			get_rows_num(t_list *model);
int			get_columns_num(char *line); // check this???
int			get_cols_num(t_cor *pts_list);
void		del(void *content);
#endif
