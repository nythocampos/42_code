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

// TODO: 
// - fix angle
/*static void	initialize_mod(t_cor *cor, t_ptn *ptn, t_state *state)
{
	cor->x = cor->x + 1;
	cor->y = cor->y + 1;
	cor->z = cor->z + 1;

	//cor->x = cor->x - (state->models->cols_len / 2);
	//cor->y = cor->y - (state->models->val_len / 2);
	//cor->z = cor->z - (state->models->rows_len / 2);
	//cor->z = cor->z - (state->models->rows_len / 2);

	scale_model(cor, 0, 0.2, 0.8);
	rotate_model(cor, 1.3, 0.2, 0.2);
	scale_model(cor, 60, 60, 0.2);
	move_model(cor, 0, 0, 2);
	ft_printf("x: %d, y: %d, z:%d\n",(int)cor->x, (int)cor->y, (int)cor->z); 
	project_model(cor);
	//scale_projection(cor, 0.05, 0.05);
	cor->x = cor->x + (WIDTH / 2);
	cor->y = cor->y + (HEIGHT / 2);

	ptn->x = (int) cor->x;
	ptn->y = (int) cor->y;
	ft_printf("x: %d, y: %d\n",(int)cor->x, (int)cor->y);
	return ;
	ft_printf("%d",(state->models->cols_len / 2));
}*/

static void	initialize_mod(t_cor *cor, t_ptn *ptn, t_state *state)
{
	//cor->x = cor->x + 1;
	//cor->y = cor->y + 1;
	if (cor->y >= (state->models->val_len/2))
		cor->y = cor->y - state->models->val_len;
	else
		cor->y = cor->y + state->models->val_len;
	cor->z = (state->models->rows_len - cor->z);

	cor->x = cor->x - (state->models->cols_len / 2);
	cor->y = cor->y - (state->models->val_len / 2);
	cor->z = cor->z - (state->models->rows_len / 2);
	//rotate_model(cor, 2.5, 0.5, 0.2);// 1, 0.2, 0.2 basic z
	rotate_model(cor, 0, 0, 0);// 1, 0.2, 0.2 basic z
	cor->x = cor->x + (state->models->cols_len / 2);
	cor->y = cor->y + (state->models->val_len / 2);
	cor->z = cor->z + (state->models->rows_len / 2);
	//cor->z = cor->z * (2 * state->models->rows_len);
	move_model(cor, 0, 0, 5);

	//ft_printf("x: %d, y: %d, z:%d\n",(int)cor->x, (int)cor->y, (int)cor->z); 
	project_model(cor);
	scale_projection(cor, 0.2, 0.2);
	cor->x = cor->x + (WIDTH / 2);
	cor->y = cor->y + (HEIGHT / 2);

	ptn->x = (int) cor->x;
	ptn->y = (int) cor->y;
	ft_printf("x: %d, y: %d\n",(int)cor->x, (int)cor->y);
	return ;
	ft_printf("%d",(state->models->cols_len / 2));
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

