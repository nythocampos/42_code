
// world coordinates {x,y,z}
// TODO: update this to work with float
typedef struct
{
	float	x;
	float	y;
	float	z;
	int	id;
}	t_cor;

// screen face [{x,y},[{x,y},[{x,y}]
typedef struct{
	t_cor	*points;
	int	id;
} t_face;
// --- --- ---

/*
 * ang: angles
 * n_pos: new position
 * slc: scale
 */
typedef struct {
	t_cor	*ang;
	t_cor	*n_pos;
	t_cor	*scl;
} t_ctl;

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
	int	bpp;
	int	size_line;
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
	t_ctl	*ctl;
}	t_mlx_data;


