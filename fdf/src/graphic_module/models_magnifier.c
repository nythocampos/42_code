/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models_magnifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:42:08 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/05 13:42:11 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static void	scale_model(t_cor *cor, void *scale)
{
	t_cor	*scl;

	scl = (t_cor *) scale;
	cor->x = cor->x * scl->x;
	cor->y = cor->y * scl->y;
	cor->z = cor->z * scl->z;
}

void	magnify_model(t_list *model, t_cor *scale)
{
	process_lists(model, (void *) scale, scale_model);
}
