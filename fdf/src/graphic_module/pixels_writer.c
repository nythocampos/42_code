/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_builder.c                                    	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:12:50 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/18 18:46:32 by antcampo         ###   ########.fr       */
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

void	draw_pixel(t_state *state, t_cor *cor, int color)
{
	t_img	*img;

	img = state->mlx_data->img;
	set_pixel(img, cor->x, cor->y, color);
	//refresh_window(state);
}

t_ipixels_writer	*create_pixels_writer()
{
	t_ipixels_writer	*pw;

	pw = (t_ipixels_writer *) malloc(sizeof(t_ipixels_writer) * 1);
	if (!pw)
		return (NULL);
	pw->set_pixel = &set_pixel;
	pw->write_pixel = &draw_pixel;
	return (pw);
}
