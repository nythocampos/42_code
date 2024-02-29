
#include "../../fdf.h"

/*
 * This function convert 3D world space coordinates to
 * 2D screen space coordinates
 *
 *
 * */
int	convert_3d_to_2d(int coordinate, int z_coordinate, int a)
{
	int	result;

	result = coordinate / (z_coordinate * tan(a / 2));
	return (result);
}

/*
 * This function config the x = 0, y = 0 on the center of the screen
 * */
//void	correct_screen_space(){}
