/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:57:25 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/16 01:29:20 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_vec
{
	int	dy;
	int	dx;
	int	step_x;
	int	step_y;
	int	temp_x;
	int	temp_y;
	int	p;
}	t_vec;

// world coordinates {x,y,z}
typedef struct s_cor
{
	float	x;
	float	y;
	float	z;
}	t_cor;

typedef struct s_p_data
{
	float	f_near;
	float	f_far;
	float	f_fov;
	float	f_asp_rad;
	float	f_fov_rad;
}	t_p_data;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	t_img	*img;
}	t_mlx_data;

/*
 * This model allows a easy way to access
 * to the most important information
 * in the promgram
 */
typedef struct s_state
{
	t_mlx_data	*mlx_data;
}	t_state;
