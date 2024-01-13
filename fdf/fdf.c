#include "fdf.h"

/*
 * This function 
 */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void  set_pixels()
{
  img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
}


int	main(void)
{
  t_mlx_data data;

  // Set window
	data.mlx_ptr = mlx_init();
  if(data.mlx_ptr == NULL)
    return (0);
	data.win_ptr = mlx_new_window(data.mlx_ptr,
                          WINDOW_WIDTH,
                          WINDOW_HEIGHT,
                          "Hello world!");
  if (data.win_ptr == NULL)
  {
    mlx_destroy_display(data.mlx_ptr);
    free(data.mlx_ptr); 
    return (0);

  }

  // Set Images
  set_pixels();

  // Set event
  ft_printf("Set events");
  set_events(data);

  // Start loop
	mlx_loop(data.mlx_ptr);
}
