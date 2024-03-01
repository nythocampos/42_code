
// world coordinates {x,y,z}
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
	float	x;
	float	y;
	int	id;
}	t_s_cor;

// screen face [{x,y},[{x,y},[{x,y}]
typedef struct{
	t_s_cor	*points;
	int	id;
} t_face;
// --- --- ---
// TODO: !!!FIX THIS
typedef struct {
	float	f_near;
	float	f_far;
	float	f_fov;
	float	f_asp_rad;
	float	f_fov_rad;
}	t_p_data;

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


