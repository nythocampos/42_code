/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models_magnifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:42:08 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/18 16:26:57 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	magnify_model(t_cor *cor, void *scale)
{
	t_cor	*scl;

	scl = (t_cor *) scale;
	cor->x = cor->x * scl->x;
	cor->y = cor->y * scl->y;
	cor->z = cor->z * scl->z;
}

void	scale_model(t_list *model, float x, float y, float z)
{
	t_cor	scale;

	scale.x = x;
	scale.y = y;
	scale.z = z;
	process_lists(model, (void *) &scale, magnify_model);
}
