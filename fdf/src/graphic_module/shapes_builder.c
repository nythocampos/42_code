/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:40:26 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/20 16:08:48 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	draw_y(t_mlx_data *mlx, t_vec *vec, t_cor *b)
{
	vec->p = 2 * vec->dx - vec->dy;
	while (vec->temp_y != (int) b->y)
	{
		set_pixel(mlx->img, vec->temp_x, vec->temp_y,
			COLOR_B);
		vec->temp_y = vec->temp_y + vec->step_y;
		if (vec->p >= 0)
		{
			vec->temp_x = vec->temp_x + vec->step_x;
			vec->p = vec->p - (2 * vec->dy);
		}
		vec->p = vec->p + (2 * vec->dx);
	}
}

void	draw_x(t_mlx_data *mlx, t_vec *vec, t_cor *b)
{
	vec->p = 2 * vec->dy - vec->dx;
	while (vec->temp_x != (int) b->x)
	{
		set_pixel(mlx->img, vec->temp_x, vec->temp_y,
			COLOR_B);
		vec->temp_x = vec->temp_x + vec->step_x;
		if (vec->p >= 0)
		{
			vec->temp_y = vec->temp_y + vec->step_y;
			vec->p = vec->p - (2 * vec->dx);
		}
		vec->p = vec->p + (2 * vec->dy);
	}
}

void	set_vec(t_vec *vec, t_cor *a, t_cor *b)
{
	vec->dy = (int)(b->y - a->y);
	vec->dx = (int)(b->x - a->x);
	vec->temp_x = (int) a->x;
	vec->temp_y = (int) a->y;
}

void	draw_line(t_mlx_data *mlx, t_cor *a, t_cor *b)
{
	t_vec	vec;

	set_vec(&vec, a, b);
	if (vec.dx > 0)
		vec.step_x = 1;
	else
	{
		vec.step_x = -1;
		vec.dx = -vec.dx;
	}
	if (vec.dy > 0)
		vec.step_y = 1;
	else
	{
		vec.step_y = -1;
		vec.dy = -vec.dy;
	}
	if (vec.dx >= vec.dy)
		draw_x(mlx, &vec, b);
	else
		draw_y(mlx, &vec, b);
}
