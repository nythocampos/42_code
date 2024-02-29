
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
	int	x;
	int	y;
	int	id;
}	t_s_cor;

// screen face [{x,y},[{x,y},[{x,y}]
typedef struct{
	t_s_cor	*scr_cor;
	int	id;
} t_face;
// --- --- ---
// TODO: !!!FIX THIS
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


