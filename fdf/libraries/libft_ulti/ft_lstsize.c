/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:11:33 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/29 11:12:15 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int				size;
	struct s_list	*node_ptr;

	node_ptr = lst;
	size = 1;
	if (lst == 0)
		return (0);
	while (node_ptr->next != NULL)
	{
		node_ptr = node_ptr->next;
		size++;
	}
	return (size);
}
/*
This function returns the size of the linked list
@param lst (t_list **): A pointer to the first node of the linked list
@return size (int): the number of nodes in the linked list
*/
/*int  main(void)
{
  struct s_list  *node_ptr0;
  struct s_list  *node_ptr1;
  struct s_list  *node_ptr2;
  struct s_list  *node_ptr3;
  node_ptr0 = ft_lstnew("perro");
  node_ptr1 = ft_lstnew("gato");
  node_ptr2 = ft_lstnew("caballo");
  node_ptr0->next = node_ptr1;
  node_ptr1->next = node_ptr2;
  node_ptr2->next = NULL;
  printf("node 0->%s\n", (char *)node_ptr0->content);
  printf("node 1->%s\n", (char *)node_ptr1->content);
  printf("node 2->%s\n", (char *)node_ptr2->content);
  printf("linked list size %d\n", ft_lstsize(node_ptr3));
  return (0);
}*/
