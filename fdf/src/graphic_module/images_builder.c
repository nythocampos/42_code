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

static void	initialize_mod(t_cor *cor, t_ptn *ptn, t_state *state)
{
	cor->z = (state->models->rows_len - cor->z);

	cor->x = cor->x - (state->models->cols_len / 2);
	cor->y = cor->y - (state->models->val_len / 2);
	cor->z = cor->z - (state->models->rows_len / 2);
	rotate_model(cor, 0.8, 0, 0);
	cor->x = cor->x + (state->models->cols_len / 2);
	cor->y = cor->y + (state->models->val_len / 2);
	cor->z = cor->z + (state->models->rows_len / 2);
	move_model(cor, 0, 0, 8);

	project_model(cor);
	scale_projection(cor, 0.5, 0.5);
	cor->x = cor->x + (WIDTH / 8);
	cor->y = cor->y + (HEIGHT / 8);

	ptn->x = (int) cor->x;
	ptn->y = (int) cor->y;
	ptn->y = (HEIGHT - ptn->y);
}

void	draw_vector(t_cor *a, t_cor *b, t_state *state)
{	
	t_mlx_data	*mlx;
	t_cor		tmp_a;
	t_cor		tmp_b;
	t_ptn		ptn_a;
	t_ptn		ptn_b;

	tmp_a.x = a->x;
	tmp_a.y = a->y;
	tmp_a.z = a->z;
	tmp_b.x = b->x;
	tmp_b.y = b->y;
	tmp_b.z = b->z;
	mlx = state->mlx_data;
	initialize_mod(&tmp_a, &ptn_a, state);
	initialize_mod(&tmp_b, &ptn_b, state);

	draw_line(mlx, &ptn_a, &ptn_b);
	return ;
	set_pixel(mlx->img, tmp_a.x, tmp_a.y, COLOR_B);
	set_pixel(mlx->img, tmp_b.x, tmp_b.y, COLOR_B);
}

