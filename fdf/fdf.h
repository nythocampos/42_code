/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:03:34 by antcampo          #+#    #+#             */
/*   Updated: 2023/12/29 21:49:06 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// defs
#ifndef FDF_H
# define FDF_H

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400

//TODO: check what is being imported twice

// includes
#include <X11/keysym.h>
#include <stdlib.h>

// structs
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx_data;

// a node is the most basic shape
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
	s_element_node	*shape[];//initial coordinates of every point and line that compone the object
	int	*size;//define the size of the element drawed
} t_element;

typedef struct	s_area
{
	void	*avaliable_area[]//coordinates where a node can be pleased
} t_area;

// Functions
//events_manager

//hooks
void	minimize_window(t_mlx_data *data)
void	end_program(t_mlx_data *data);

#endif
