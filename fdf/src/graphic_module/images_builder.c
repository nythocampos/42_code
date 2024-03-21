/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_builder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:12:50 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/20 16:26:20 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

/*
 * This function the pixels direct to the space of memory
 * TODO: move this to a better place
 */
void	set_pixel(t_img *img, int x, int y, int color)
{
	int	offset;

	if (x > WIDTH || y > HEIGHT || x < 0 || y < 0)
		return ;
	offset = (img->size_line * y) + (x * (img->bpp / 8));
	*((unsigned int *)(offset + img->addr)) = color;
}

static void	initialize_mod(t_cor *cor)
{
	cor->x = cor->x + 1;
	cor->y = cor->y + 1;
	cor->z = cor->z + 1;
	scale_model(cor, 1, 0.1, 0.1);
	move_model(cor, 0, -0.1, 0);
	rotate_model(cor, 0.5, 0.02, 1); // keep testing with X
	move_model(cor, (cor->x/2), (cor->y/2)+50, 3);

	project_model(cor);
	scale_projection(cor, 0.05, 0.05);
}

void	draw_vector(t_cor *a, t_cor *b, t_mlx_data *mlx)
{
	t_cor	tmp_a;
	t_cor	tmp_b;

	tmp_a.x = a->x;
	tmp_a.y = a->y;
	tmp_a.z = a->z;
	tmp_b.x = b->x;
	tmp_b.y = b->y;
	tmp_b.z = b->z;
	initialize_mod(&tmp_a);
	initialize_mod(&tmp_b);
	draw_line(mlx, &tmp_a, &tmp_b);
	return ;
	set_pixel(mlx->img, tmp_a.x, tmp_a.y, COLOR_B);
	set_pixel(mlx->img, tmp_b.x, tmp_b.y, COLOR_B);
}

void	draw_cor(t_cor *cor, t_mlx_data *mlx)
{
	t_cor	tmp_cor;

	tmp_cor.x = cor->x;
	tmp_cor.y = cor->y;
	tmp_cor.z = cor->z;
	initialize_mod(&tmp_cor);
	set_pixel(mlx->img, tmp_cor.x, tmp_cor.y,
			COLOR_B);
}


