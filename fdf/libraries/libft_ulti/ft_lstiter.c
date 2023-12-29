/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:57:59 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/29 15:58:17 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	struct s_list	*node_ptr;

	if (lst == NULL)
		return ;
	node_ptr = lst;
	while (node_ptr->next != NULL)
	{
		f(node_ptr->content);
		node_ptr = node_ptr->next;
	}
	f(node_ptr->content);
}

/*
This function apply the (*f) function to the content of each node.

@param lst (t_list *):  a pointer to the first node
@param del (*del): a pointer to the function
*/