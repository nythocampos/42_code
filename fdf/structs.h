/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:57:25 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/15 23:08:48 by antcampo         ###   ########.fr       */
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
	int		id;
}	t_cor;

// screen face [{x,y},[{x,y},[{x,y}]
typedef struct s_face
{
	t_cor	*points;
	int		id;
}	t_face;
// --- --- ---

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
 * model_data (t_list *): the model coordinates in a list.
 * model_faces (t_face *): the model coordinates group in faces.
 * model_proj (t_face *): the model projection.
 * id (int): the model id.
 */
typedef struct s_models
{
	t_list	*model_data;
	t_face	*model_faces;
	//t_face	*model_proj;
	int		id;
}	t_models;
/*
 * This model allows a easy way to access
 * to the most important information
 * in the promgram
 */
typedef struct s_state
{
	t_mlx_data	*mlx_data;
	t_models	*models;
}	t_state;
