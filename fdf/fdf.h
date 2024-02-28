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

// structs ------------------------------

// a node is the most basic shape
// matrix coordinates
// world coordinates {x,y,z}

// world coordinates
typedef struct
{
	int	x;
	int	y;
	int	z;
	int	id;
}	t_w_cor;

// screen coordinates {x, y}
typedef struct
{
	int	x;
	int	y;
}	t_s_cor;

// world triangle [{x,y,z},[{x,y,z},[{x,y,z}]
typedef struct
{
	t_w_cor	*w_cor;
}	t_w_tri;

// screen triangle [{x,y},[{x,y},[{x,y}]
typedef struct
{
	t_s_cor	*scr_cor;
}	t_s_tri;
// --- --- ---
/*typedef struct	s_p_mtr
{
	float	f_near = 0.1;
	float	f_far = 1000.0;
	float	f_fov = 90.0;
	float	f_asp_rat = hight / width;
	float	f_fov_rat = 1.0 / tan(f_fov *0.5/ 180.0 * 3.14159);
}	t_p_mtr;*/

typedef struct	{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_img;

typedef struct	
{
	void	*mlx;
	void	*win;
	t_img	*img;
	int	width;
	int	hight;
	char	*title;
}	t_mlx_data;

// Functions ------------------------------

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
