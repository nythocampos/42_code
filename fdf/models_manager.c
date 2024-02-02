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

#include "fdf.h"

int	get_columns_num(char *line)
{
	int	index;
	int	column_num;

	index = 1;
	column_num = 0;
	while (line[index] != '\0')
	{
		if ((line[index - 1] >= 48 && line[index - 1] <= 57) && 
			(line[index] < 48 || line[index] > 57))
			column_num++;
		index++;
	}
	return (column_num);
}

int get_item_value(char *str, int end)
{
	int   num;
	char  *str_num;
	int   start;
	int   index;

	start = end;
	index = 0;
	num = 0;
	while (str[start - 1] >= 48 && str[start - 1] <= 57)
		start--;
	str_num = (char *) malloc(sizeof(char) * (end - start + 1));
	if (!str_num)
		return (0);
	while (start <= end)
	{
		str_num[index] = str[start];
		index++;
		start++;
	}
	str_num[index] = '\0';
	num = ft_atoi(str_num);
	free(str_num);
	return (num);
}
/*
* This function is used to choose the process to follow
* considering the format of model to load
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
