/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_builder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:12:50 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/25 16:14:22 by antcampo         ###   ########.fr       */
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

static float	get_scale(t_state *state)
{
	float	scale_f;
	int		cols_len;
	int		rows_len;

	cols_len = state->models->cols_len;
	rows_len = state->models->rows_len;
	scale_f = fminf((HEIGHT / rows_len), (WIDTH / cols_len));
	return (scale_f);
}

static void	move_model_pos(t_cor *cor, t_state *state)
{
	cor->z = (state->models->rows_len - cor->z);
	cor->x = cor->x - (state->models->cols_len / 2);
	cor->y = cor->y - (state->models->val_len / 2);
	cor->z = cor->z - (state->models->rows_len / 2);
	rotate_model(cor, M_PI*0.2, -M_PI_4, 0); //M_PI*0.2, -M_PI_4, 0
	cor->x = cor->x + (state->models->cols_len / 2);
	cor->y = cor->y + (state->models->val_len / 2);
	cor->z = cor->z + (state->models->rows_len / 2);
	move_model(cor, 0, 0, 8);
}

/*
 * This function initialize the parameters of the model
 * - initialize the position and rotation
 * - projects the model
 * - scale the projection
 * - move the projection
 */
static void	initialize_mod(t_cor *cor, t_ptn *ptn, t_state *state)
{
	float	scale_f;

	scale_f = get_scale(state);
	move_model_pos(cor, state);
	project_model(cor);
	cor->x = cor->x *(scale_f * (state->models->cols_len * 0.5));
	cor->y = cor->y *(scale_f * (state->models->rows_len * 0.5));
	ptn->x = (int)(cor->x + (WIDTH * 0.01));
	ptn->y = (int)(cor->y + (HEIGHT / 2));
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
}
