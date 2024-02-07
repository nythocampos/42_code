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

/*typedef struct s_coordinates
{
	int	x;
	int	y;
	int	z;
} t_coordinates;

typedef struct s_element_node
{
	struct s_coordinates	*position;
	struct s_coordinates	**linked_to;

} t_element_node;

typedef struct	s_element
{
	struct s_coordinates	*position;
	struct s_element_node	**shape;
	int						scale;
} t_element;*/

typedef struct	s_frame {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_frame;

typedef struct	s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int	width;
	int	hight;
	char	*title;
}	t_mlx_data;

typedef struct	s_perspective
{
	int	a;
	int	n;
}	t_perspective;


typedef struct	s_world_coor
{
	int	x;
	int	y;
	int	z;
}	t_world_coor;

// Functions ------------------------------

// Window section
void	set_events(t_mlx_data data);
void	minimize_window(t_mlx_data *data);
void	end_program(t_mlx_data *data);
void	run_window();
void	initializate_window();

// Models manager section
int	get_columns_num(char *line);
int	get_item_value(char *str, int end);

// Frame builder section
t_mlx_data	*init_mlx_data();
t_mlx_data	*build_frame();

//utils
int	convert_3d_to_2d(int coordinate, int z_coordinate, int a);

#endif
