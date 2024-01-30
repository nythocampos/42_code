/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:06:05 by antcampo          #+#    #+#             */
/*   Updated: 2024/01/30 16:02:47 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	node_list_len(struct s_element_node **nodes_list)
{
	int	index;
	
	index = 0;
	while (nodes_list[index] != NULL)
	{
	
		//ft_printf("index: %d\n", index);
		index++;
	}
	return index;
}

t_element_node	**lst_join(struct s_element_node **n_list1, struct s_element_node **n_list2)
{
	struct s_element_node	**new_list;
	int						lst1_len;
	int						lst2_len;
	int						index;

	lst1_len = node_list_len(n_list1);
	lst2_len = node_list_len(n_list2);
	ft_printf("lst1: %d\n", lst1_len);
	ft_printf("lst2: %d\n", lst2_len);

	if (!n_list2)
		return (NULL);
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
	free(&n_list1);
	return (new_list);
}

