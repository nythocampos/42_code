
#include "fdf.h"

/*
 * This function generates the image
 *
 * Args:
 * 	mlx_data (t_mlx_data): the object where the data is storage
 * */
static void	generate_image(t_mlx_data *mlx_data)
{
	mlx_data->img_ptr = mlx_new_image(
			mlx_data->mlx_ptr,
		       	mlx_data->width,
		       	mlx_data->hight
			);
}

/*
 * This function generates the window
 * */
static void	generate_window(t_mlx_data *mlx_data)
{
	mlx_data->mlx_win = mlx_new_window(
			mlx_data->mlx_ptr,
		       	mlx_data->width,
		       	mlx_data->hight,
		       	mlx_data->title
			);
}

/*
 * This function initialice the mlx_data providing all necessary
 * information
 * */
t_mlx_data	init_mlx_data()
{
	struct s_mlx_data	*mlx_data;

	mlx_data = malloc(sizeof(t_mlx_data) * 1);
	if (!mlx_data)
		return;
	mlx_data->mlx_ptr = mlx_init();
	mlx_data->width = 800;
	mlx_data->hight = 800;
	mlx_data->title = ft_strdup("FDF");
	generate_window(mlx_data);
	generate_image(mlx_data);
	return (mlx_data);
}
