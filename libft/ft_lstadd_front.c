/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:52:31 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/29 00:40:04 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*
This function adds the node new to the beginning of the list


@param lst (t_list **): la dirección de un puntero al primer nodo de
una lista.

@param new (t_list *): un puntero al nodo que añadir al principio de
la lista.

@return void
*/
/*int	main(void)
{
	struct s_list	*node_ptr0;
	struct s_list	*node_ptr1;
	struct s_list	*node_ptr2;

	node_ptr0 = ft_lstnew("perro");
	node_ptr1 = ft_lstnew("gato");
	node_ptr2 = ft_lstnew("caballo");
	node_ptr1->next = node_ptr2;
	ft_lstadd_front(&node_ptr1, node_ptr0);
	printf("node 0->%s\n", (char *)node_ptr0->content);
	printf("node 1->%s\n", (char *)node_ptr1->content);
	printf("node 2->%s\n", (char *)node_ptr2->content);
	if (node_ptr0->next == &node_ptr1)
		printf("OK\n");
	return (0);
}*/
