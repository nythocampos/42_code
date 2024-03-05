/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:01:41 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/05 13:28:28 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

/*
* This function is used to choose the process to follow
* considering the format of model to load
*/

t_list	*load_model(char *file_name)
{
	t_list	*model;
	int		fd;

	ft_printf("File name: %s \n", file_name);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("File %s not found\n", file_name);
		return (NULL);
	}
	model = load_terrain_model(fd);
	close(fd);
	return (model);
}
