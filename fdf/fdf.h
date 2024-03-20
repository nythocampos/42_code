/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:03:34 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/20 14:13:41 by antcampo         ###   ########.fr       */
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
void				end_program();
void				set_events(t_state *data);
void				set_window(t_mlx_data *mlx_data, char *title);
void				refresh_window(t_state *state);
t_mlx_data			*create_mlx_data(void);
void				clean_mlx_data(t_mlx_data *mlx_data);
// Files module
t_ifile_loader		*create_file_loader();
int					get_item_value(char *str, int end);
int					on_item(char *line, int index);

// Models manager module
void				set_model(t_list *models, t_model *model);
t_list				*create_models_list();
t_imodel_collector	*create_fdf_collector();
t_model				*get_model(t_list *models_lst, int id);
t_imodel_updater	*create_model_updater();
t_imatrix_creator	*create_matrix_creator();
void				process_lists(
		t_list *node, void *data, void (*f)(t_cor *, float,float,float))

// Graphic module 
void				set_pixel(t_img *img, int x, int y, int color);
t_ipixels_writer	*create_pixels_writer();
void				draw_line(t_mlx_data *mlx, t_cor *a, t_cor *b);
t_imodel_printer	*create_model_printer();
t_ipixels_writer	*create_pixels_writer();
//	Shared 
void				apply_matrix(t_cor *src, void *m);
void				initialize_m(float *m, int size);
int					get_rows_num(t_list *model);
int					get_columns_num(char *line); // check this???
int					get_cols_num(t_cor *pts_list);
void				del(void *content);
void				*err_ret_num(char *location, char *err);
void				*err_ret_null(char *location, char *err);
#endif
