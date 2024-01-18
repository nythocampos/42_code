/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:03:34 by antcampo          #+#    #+#             */
/*   Updated: 2024/01/18 19:51:03 by antcampo         ###   ########.fr       */
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

// a node is the most basic shape
/*
typedef struct s_element_node
{
	int	*base;//coordinates
	int	*linked_to[];//list of directions of nodes that are pointed by this

} t_element_node;

//the element is the group of nodes
//the element can be scalable and moved
typedef struct	s_element
{
	int	*base;//coordinates where the element will be pleaced
	struct s_element_node	*shape;//initial coordinates of every point and line that compone the object
	int	*size;//define the size of the element drawed
} t_element;

typedef struct	s_area
{
	void	*avaliable_area;//coordinates where a node can be pleased
} t_area;
*/
// Functions
//events_manager
  void	set_events(t_mlx_data data);

//hooks
  void	minimize_window(t_mlx_data *data);
  void	end_program(t_mlx_data *data);

//files management
  void  manage_file_content(char *file_name);

#endif
