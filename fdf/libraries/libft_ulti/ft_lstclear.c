/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:10:15 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/29 12:10:26 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	struct s_list	*next_ptr;

	if (*lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		next_ptr = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next_ptr;
	}
}

/*
This function delete and free the node lst and all
consecutive nodes of that node

@param lst (t_list **): the address of the pointer that points a node
@param del (*del): a pointer to the function used to delete the content of a node
*/

//printf("Next node content ->%s\n", (char *)next_ptr->content);
//printf("Node deleted\n");
/*int  main(void)
{
  struct s_list  *node_ptr0;
  struct s_list  *node_ptr1;
  struct s_list  *node_ptr2;
  struct s_list  *node_ptr3;
  struct s_list  *test;
  node_ptr0 = ft_lstnew("perro");
  node_ptr1 = ft_lstnew("gato");
  node_ptr2 = ft_lstnew("caballo");
  node_ptr3 = ft_lstnew(":D");
  test = ft_lstlast(node_ptr0);
  printf("last node->%s\n", (char *)test->content);
  ft_lstadd_back(&node_ptr0, node_ptr1);
  test = ft_lstlast(node_ptr0);
  printf("last node->%s\n", (char *)test->content);
  ft_lstadd_back(&node_ptr0, node_ptr2);
  test = ft_lstlast(node_ptr0);
  printf("last node->%s\n", (char *)test->content);
  ft_lstadd_back(&node_ptr0, node_ptr3);
  test = ft_lstlast(node_ptr0);
  printf("last node->%s\n", (char *)test->content);

  ft_lstclear(&node_ptr0, &delete);
  printf("first node->%s\n", (char *)node_ptr0->content);
  return (0);
}*/
