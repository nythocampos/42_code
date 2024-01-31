/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_loader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:29:19 by antcampo          #+#    #+#             */
/*   Updated: 2024/01/31 19:21:53 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_columns_num(char *line)
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

static int get_item_value(char *str, int end)
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

static t_element_node	**convert_line(char *line, int line_num)
{
	int   					index;
	int   					column_num;
	int   					item_value;
	int						columns_num;
	struct s_coordinates	*coor;
	struct s_element_node	*element_node;
	struct s_element_node	**nodes_list;
	int						lst_index;

	index = 1;
	lst_index = 0;
	column_num = 0;
	line_num = 0;
	if (!line)
		return (NULL);
	columns_num = get_columns_num(line);
	nodes_list = malloc(sizeof(t_element_node) * (columns_num + 1));
	if (!nodes_list)
		return (NULL);
	while (line[index] != '\0' && lst_index < columns_num)
	{
		if ((line[index - 1] >= 48 && line[index - 1] <= 57) && 
			(line[index] < 48 || line[index] > 57))
		{
			item_value = get_item_value(line, index);

			coor = malloc(sizeof(t_coordinates) * 1);
			element_node = malloc(sizeof(t_element_node) * 1);

			coor->x = column_num;
			// !!!! FIX item_value
			coor->y = item_value;
			coor->z = line_num;

			//!!!! check if coor is being passed to position
			// maybe adding a & this can be changed
			element_node->position = coor;
			//	define the list of nodes linked to this node
			//	element_node->linked_to
			nodes_list[lst_index] = element_node;
			//!! Free element_node here because the direction of the node was
			// passed to the nodes_list[lst_index] it is the same with coor
			column_num++;
			lst_index++;
		}
		index++;
	}
	nodes_list[index] = NULL;
	return (nodes_list);
}

static t_element	*initialice_model()
{
	struct s_element		*model;
	struct s_coordinates	*coor;
	
	coor = malloc(sizeof(t_coordinates) * 1);
	coor->x = 0;
	coor->y = 0;
	coor->z = 0;
	model = malloc(sizeof(t_element) * 1);
	model->scale = 1;
	model->position = coor;
	return (model);
}

/*
 * This function loads the content of the file
 */
t_element	*load_terrain_model(int file_df)
{
	// load file data and convert it to a obj
	int   					line_num;
	char  					*temp_line;
	struct s_element  		*model;
	struct s_element_node	**nodes_list;
	struct s_element_node	**temp;

	line_num = 0;
	temp_line = (char *) malloc(sizeof(char) * 1);
	nodes_list = malloc(sizeof(t_element_node) * 1);
	temp = malloc(sizeof(t_element_node) * 1);

	if (!temp_line || !nodes_list || !temp)
		return (NULL);

	temp_line[0] = '\0';
	temp[0] = NULL;
	nodes_list[0] = NULL;
	model = initialice_model();

	if (!model)
		return (NULL);
	while (temp_line)
	{
		ft_printf("Test 0\n");
		free(temp_line);
		ft_printf("Test 0.1\n");
		temp_line = get_next_line(file_df);
		ft_printf("%s", temp_line);
		temp = convert_line(temp_line, line_num);
		// append nodes_list to the element
		ft_printf("temp converted\n");
		nodes_list = lst_join(nodes_list, temp);
		if (!nodes_list)
			return (NULL);
		line_num++;
	}
	ft_printf("Fill shape finished\n");
	free_nodes_list(temp);
	model->shape = nodes_list;
	return (model);
}

