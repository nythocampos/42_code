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

// defs
#ifndef FDF_H
# define FDF_H

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400
#define XK_Escape	0xff1b

//TODO: check what is being imported twice

#include "libraries/mlx/mlx.h"
#include <fcntl.h>
#include <stdlib.h>
#include "libraries/libft_ulti/libft.h"
// structs

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
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_frame;

typedef struct	s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
}	t_mlx_data;

// Functions

// Window section
void	set_events(t_mlx_data data);
void	minimize_window(t_mlx_data *data);
void	end_program(t_mlx_data *data);
void	run_window();
void	initializate_window();

// Models manager section
/*
t_element	*load_terrain_model(int file_df);
t_element	*load_model(char *file_name);
int			node_list_len(struct s_element_node **nodes_list);
t_element_node	**lst_join(struct s_element_node **n_list1, struct s_element_node **n_list2);
void	free_nodes_list(struct s_element_node **nodes_list);*/

// Frame builder section
void	build_frame();

#endif
