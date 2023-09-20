/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:24:10 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/19 11:24:16 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	to_find;

	to_find = (char) c;
	while (1)
	{
		if ((*s == to_find) || (*s == '\0' && to_find == '\0'))
			return ((char *)s);
		if (*s == '\0')
			break ;
		s++;
	}
	return ((char *) '\0');
}
