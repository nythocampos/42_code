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

void	draw_cor(t_cor *cor, t_mlx_data *mlx)
{
	set_pixel(mlx->img, cor->x, cor->y,
			COLOR_B);
}
