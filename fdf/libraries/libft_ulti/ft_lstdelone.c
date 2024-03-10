/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:14:02 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/29 11:14:23 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*
This function free the memory of the content of the node and free the node

@param lst (t_list *): A pointer to the node
@param del (*del): A pointer to the function to use
@return void
*/
/*int  main(void)
{
  struct s_list  *node_ptr0;
  struct s_list  *node_ptr1;
  struct s_list  *node_ptr2;
  struct s_list  *node_ptr3;
  struct s_list  *test;
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
