/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:05:18 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/19 12:05:19 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	to_find;
	int		found;
	char	*last_found;

	to_find = (char) c;
	found = 0;
	while (1)
	{
		if ((*s == to_find) || (*s == '\0' && to_find == '\0'))
		{
			found = 1;
			last_found = (char *) s;
		}
		if (*s == '\0')
			break ;
		s++;
	}
	if (found == 1)
		return (last_found);
	return ((char *) '\0');
}
