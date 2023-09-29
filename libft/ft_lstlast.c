/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 01:09:15 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/29 01:18:37 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	struct s_list	*node_ptr;

	node_ptr = lst;
	if (lst == 0)
		return (0);
	while (node_ptr->next != NULL)
		node_ptr = node_ptr->next;
	return (node_ptr);
}

/*
This function returns the last node of the linked list

@param lst (t_list **): A pointer to the first node of the linked list

@return node_ptr (t_list): the last node of the linked list
*/
/*int	main(void)
{
	struct s_list	*node_ptr0;
	struct s_list	*node_ptr1;
	struct s_list	*node_ptr2;
	struct s_list	*node_ptr3;

	node_ptr0 = ft_lstnew("perro");
	node_ptr1 = ft_lstnew("gato");
	node_ptr2 = ft_lstnew("caballo");
	node_ptr0->next = node_ptr1;
	node_ptr1->next = node_ptr2;
	node_ptr2->next = NULL;
	printf("node 0->%s\n", (char *)node_ptr0->content);
	printf("node 1->%s\n", (char *)node_ptr1->content);
	printf("node 2->%s\n", (char *)node_ptr2->content);
	node_ptr3 = ft_lstlast(node_ptr0);
	if (node_ptr3 != 0)
		printf("last node->%s\n", (char *)node_ptr3->content);
	return (0);
}*/
