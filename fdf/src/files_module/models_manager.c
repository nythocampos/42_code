/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:01:41 by antcampo          #+#    #+#             */
/*   Updated: 2024/01/27 11:02:16 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

/*
* This function is used to choose the process to follow
* considering the format of model to load
*/

t_list	*load_model(char *file_name)
{
	//char  	*file_extension;
	t_list	*model;
	//int	extension_len;
 	int	fd;

	//file_extension = ft_strchr(file_name, 46);
	//extension_len = ft_strlen(file_extension);
	ft_printf("File name: %s \n", file_name);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("File %s not found\n", file_name);
		return (NULL);
	}
	model = load_terrain_model(fd);
	//TODO: add close
	close(fd);
	
	/*if (ft_strncmp(file_extension, ".fdf", extension_len) == 0)
	{
		// call process to load fdf file
		ft_printf("Loading fdf file fd: %d... \n", file_fd);
    		model = load_terrain_model(file_fd);
	 	ft_printf("FDF file loaded \n");
	}
	else
	{
		//ft_strncmp(file_extension, ".obj", extension_len) == 0
		model = load_terrain_model(file_fd);
		// call process to load obj file
		ft_printf("Obj file loaded \n");
	}*/

	return (model);
}
