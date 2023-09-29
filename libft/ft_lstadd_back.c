/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 01:20:35 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/29 02:07:27 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	struct s_list	*node_ptr;

	if (new == 0)
		return ;
	if (*lst == 0)
	{
		*lst = new;
	}
	else
	{
		node_ptr = *lst;
		node_ptr = ft_lstlast(*lst);
		node_ptr->next = new;
		new->next = NULL;
	}
}
/*
This function adds a node to the end of the linked list

@param lst (t_list **): A pointer to the first node of the linked list
@param new (t_list *): A pointer to the new node to be added

@return void
*/
/*int	main(void)
{
	struct s_list	*node_ptr0;
	struct s_list	*node_ptr1;
	struct s_list	*node_ptr2;
	struct s_list	*node_ptr3;
	struct s_list	*test;

	//node_ptr0 = ft_lstnew("perro");
	node_ptr1 = ft_lstnew("gato");
	node_ptr2 = ft_lstnew("caballo");
	node_ptr3 = ft_lstnew(":D");
	// test = ft_lstlast(node_ptr0);
	// printf("last node->%s\n", (char *)test->content);
	ft_lstadd_back(&node_ptr0, node_ptr1);
	test = ft_lstlast(node_ptr0);
	printf("last node->%s\n", (char *)test->content);
	ft_lstadd_back(&node_ptr0, node_ptr2);
	test = ft_lstlast(node_ptr0);
	printf("last node->%s\n", (char *)test->content);
	ft_lstadd_back(&node_ptr0, node_ptr3);
	test = ft_lstlast(node_ptr0);
	printf("last node->%s\n", (char *)test->content);
	printf("first node->%s\n", (char *)node_ptr0->content);
	return (0);
}*/