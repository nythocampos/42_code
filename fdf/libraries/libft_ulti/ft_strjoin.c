/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:28:01 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/23 22:49:32 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * This function concat 2 strings and return a new string with the result
 *
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t  str_size;
  int     s1_len;
  int     s2_len;
	char		*str;

  s1_len = ft_strlen(s1);
  s2_len = ft_strlen(s2);
	if (s1 == 0 || s2 == 0)
		return (0);
	if ((s1_len <= 0 && s2_len <= 0))
		return ((char *)ft_calloc(1, sizeof(char)));
	str_size = s1_len + s2_len;
	str = (char *)ft_calloc(str_size + 1, sizeof(char));
	if (str == 0)
		return (0);
	if (s1[0] != 0)
		ft_memcpy(str, (const char *)s1, s1_len);
	if (s2[0] != 0)
		ft_memcpy(&str[s1_len], (const char *)s2, s2_len);
	return (str);
}

//Concat 2 strings
/*int	main(void)
{
	printf("%zu\n", ft_strlen(""));
	printf("Test: 0-->%s\n", ft_strjoin(NULL, "corriendo"));
	printf("Test: 1-->%s\n", ft_strjoin(" ", "corriendo"));
	printf("Test: 2-->%s\n", ft_strjoin(" ", " "));
	printf("Test: 3-->%s\n", ft_strjoin("", " "));
	printf("Test: 4-->%s\n", ft_strjoin(" ", ""));
	printf("Test: 5-->%s\n", ft_strjoin("", ""));
	printf("Test: 6-->%s\n", ft_strjoin("", " hello"));
}*/
