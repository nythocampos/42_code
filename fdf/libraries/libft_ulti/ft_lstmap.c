/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:09:06 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/29 16:09:11 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_list(t_list *new_list, void (*del)(void *))
{
	ft_lstclear(&new_list, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	struct s_list	*node_ptr;
	struct s_list	*result_ptr;
	struct s_list	*last_ptr;
	struct s_list	*new_list;

	if (lst == 0 || f == 0 || del == 0)
		return (NULL);
	node_ptr = lst;
	last_ptr = NULL;
	while (1)
	{
		result_ptr = ft_lstnew(f(node_ptr->content));
		if (result_ptr == NULL)
			return (free_list(new_list, del));
		if (last_ptr != NULL)
			last_ptr->next = result_ptr;
		else
			new_list = result_ptr;
		last_ptr = result_ptr;
		if (node_ptr->next == NULL)
			break ;
		node_ptr = node_ptr->next;
	}
	return (new_list);
}

/*
This function apply the (*f) function to the content of each node.
Return a new linked list with the result if the everything went well.

@param lst (t_list *): A pointer to the node
@param f (*f): The address of the function to apply
@param del (*del): The address of the function used to delete 
				the content of the node
*/