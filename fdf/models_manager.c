/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:01:41 by antcampo          #+#    #+#             */
/*   Updated: 2024/01/26 17:48:39 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
* This function is used to choose the process to follow
* considering the type of file to load
*/
t_element	*load_model(char *file_name)
{
	char  				*file_extension;
	struct s_element	*model;
	int	  				extension_len;
 	int   				file_fd;

	// if the file loaded
	file_extension = ft_strchr(file_name, 46);
	extension_len = ft_strlen(file_extension);
	file_fd = open(file_name, O_RDONLY);
	if (ft_strncmp(file_extension, ".fdf", extension_len) == 0)
	{
		// call process to load fdf file
    	model = load_terrain_model(file_fd);
	 	ft_printf("Fdf file loaded \n");
	}
	else
	{
		//ft_strncmp(file_extension, ".obj", extension_len) == 0
		model = load_terrain_model(file_fd);
		// call process to load obj file
		ft_printf("Obj file loaded \n");
	}

	return (model);
}
