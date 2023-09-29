/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:30:43 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/28 20:50:51 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	struct s_list	*node_ptr;

	node_ptr = malloc(sizeof(struct s_list));
	node_ptr->content = content;
	node_ptr->next = NULL;
	return (node_ptr);
}
