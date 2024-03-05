/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:57:25 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/05 13:57:29 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// world coordinates {x,y,z}
typedef struct s_cor
{
	float	x;
	float	y;
	float	z;
	int		id;
}	t_cor;

// screen face [{x,y},[{x,y},[{x,y}]
typedef struct s_face
{
	t_cor	*points;
	int		id;
}	t_face;
// --- --- ---

/*
 * ang: angles
 * n_pos: new position
 * slc: scale
 */
typedef struct s_ctl
{
	t_cor	*ang;
	t_cor	*n_pos;
	t_cor	*scl;
}	t_ctl;

typedef struct s_p_data
{
	float	f_near;
	float	f_far;
	float	f_fov;
	float	f_asp_rad;
	float	f_fov_rad;
}	t_p_data;

typedef struct t_img
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
	int		width;
	int		hight;
	char	*title;
	t_ctl	*ctl;
}	t_mlx_data;
