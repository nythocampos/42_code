/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:06:05 by antcampo          #+#    #+#             */
/*   Updated: 2024/01/31 19:45:17 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 * This function get the number of element_nodes storaged in a list of s_element_object
 *
 * Args:
 * 	s_element_node: nodes_list
 *
 * Return:
 * 	int: index
 * 	
 * */
static int	nodes_list_len(struct s_element_node **nodes_list)
{
	int	index;
	
	index = 0;
	while (nodes_list[index] != NULL)
		index++;
	return index;
}


/*
 * This function free all element_node in a element_node list
 *
 * Args:
 * 	nodes_list (s_element_node): the element_node list
 *
 * */
void	free_nodes_list(struct s_element_node **nodes_list)
{
	int	index;
	
	index = 0;
	ft_printf("List len: %d\n", nodes_list_len(nodes_list));
	if (!nodes_list)
		return;
	while (nodes_list[index] != NULL)
	{
		free(nodes_list[index]);
		index++;
	}
	free(nodes_list);
	//nodes_list = NULL;
}

/*
 * FIX!!!
 * This function concat two element_node lists
 *
 * Args:
 * 	n_list1 (s_element_node **): it's the first list to concat
 * 	n_list2 (s_element_node **): it's the second list to concat
 *
 * Return:
 * 	new_list (s_element_node **): it's the element_node list result after concat n_list1 and n_list2 
 * */
t_element_node	**lst_join(struct s_element_node **n_list1, struct s_element_node **n_list2)
{
	struct s_element_node	**new_list;
	int						lst1_len;
	int						lst2_len;
	int						index;

	if (!n_list1 || !n_list2)
		return (NULL);
	lst1_len = nodes_list_len(n_list1);
	lst2_len = nodes_list_len(n_list2);
	ft_printf("lst1: %d\n", lst1_len);
	ft_printf("lst2: %d\n", lst2_len);	
	new_list = malloc(sizeof(t_element_node) * (lst1_len + lst2_len));
	if (!new_list)
		return (NULL);

	index = -1;
	while (index++ < lst1_len)
		new_list[index] = n_list1[index];
	index = -1;
	while (index++ < lst2_len)
		new_list[lst1_len + index] = n_list2[index];
	new_list[lst1_len + index - 1] = NULL;

	ft_printf("Test 1\n");
	free_nodes_list(n_list1);
	//free_nodes_list(n_list2);
	ft_printf("Test 2\n");
	return (new_list);
}

