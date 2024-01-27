/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_loader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:29:19 by antcampo          #+#    #+#             */
/*   Updated: 2024/01/27 12:51:15 by antcampo         ###   ########.fr       */
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
	int   index;
	int   column_num;
	int   item_value;
	int		columns_num;
	struct s_coordinates	*coor;
	struct s_element_node	*element_node;
	struct s_element_node	**nodes_list;

	index = 1;
	column_num = 0;
	line_num = 0;
	if (!line)
		return (0);
	columns_num = get_columns_num(line);
	nodes_list = malloc(sizeof(t_element_node) * columns_num);
	if (!nodes_list)
		return (0);
	while (line[index] != '\0')
	{
		if ((line[index - 1] >= 48 && line[index - 1] <= 57) && 
			(line[index] < 48 || line[index] > 57))
		{
			column_num++;
			item_value = get_item_value(line, index);

			coor = malloc(sizeof(t_coordinates) * 1);
			element_node = malloc(sizeof(t_element_node) * 1);

			coor->x = column_num;
			coor->y = line_num;
			coor->z = item_value;

			element_node->position = coor;
			//	define the list of nodes linked to this node
			//	element_node->linked_to
			nodes_list[columns_num] = element_node;
			columns_num--;

		}
		index++;
	}
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

t_element	**lst_join(t_element_node **n_list1, t_element_node **n_list2)
{
	struct s_element_node	**new_list;
	int						lst1_len;
	int						lst2_len;
	
	lst1_len = ft_strlen(n_list1);
	lst2_len = ft_strlen(n_list2);
	new_list = malloc(sizeof(t_element_node) * (lst1_len + lst2_len));
	if (!new_list)
		return (0);
	if (n_list1[0])
		ft_memcpy(new_list, (t_element_node *)n_list1, lst1_len);
	if (n_list2[0])
		ft_memcpy(&new_list[lst1_len], (t_element_node *)n_list2, lst2_len);
	return (new_list);
}

/*
 * This function loads the content of the file
 */
t_element	*load_terrain_model(int file_df)
{
	// load file data and convert it to a obj
	int   line_num;
	char  *temp_line;
	struct s_element  *model;
	struct s_element_node	**nodes_list;
	struct s_element_node	**temp;

	line_num = 0;
	temp_line = (char *) malloc(sizeof(char) * 1);
	if (temp_line == 0)
		return (0);
	temp_line[0] = '\0';
	model = initialice_model();
	if (!model)
		return (0);
	while (temp_line != NULL)
	{
		free(temp_line);
		temp_line = get_next_line(file_df);
		//ft_printf("%s \n", temp_line);
		*temp = convert_line(temp_line, line_num);
		*nodes_list = lst_join(nodes_list, temp);
		


		// append nodes_list to the element
		line_num++;
	}
	model->shape = nodes_list;
	return (model);
}

