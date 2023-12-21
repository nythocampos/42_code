/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:53:36 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/28 12:53:38 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	struct s_list	*node;

	node = malloc(sizeof(t_list));
	if (node == 0)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
