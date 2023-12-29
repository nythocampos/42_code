/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:03:34 by antcampo          #+#    #+#             */
/*   Updated: 2023/12/29 20:03:55 by antcampo         ###   ########.fr       */
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

// functions
void	end_program(t_mlx_data *data);

#endif
