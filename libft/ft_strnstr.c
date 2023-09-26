/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:01:02 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/22 16:19:51 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*check_sub_string(char *sub_big, char *sub_little)
{
	int		index;
	int		diff;

	index = 0;
	diff = 0;
	while (sub_big[index] != '\0' && sub_little[index] != '\0')
	{
		if (sub_big[index] != sub_little[index])
		{
			diff = 1;
			break ;
		}
		index++;
	}
	if (diff == 0)
		return ((char *) &sub_big[0]);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		index;
	char	*check_sub;

	index = 0;
	if ((int) len < 0)
		len = ft_strlen(big);
	if (little[0] == '\0')
		return ((char *) big);
	while ((int) len > 0 && big[index] != '\0')
	{
		if (big[index] == little[0])
		{
			check_sub = check_sub_string((char *) &big[index], (char *) little);
			if (check_sub != 0)
			{
				len = (len - ft_strlen(little)) + 1;
				if ((int) len <= 0)
					return (0);
				return (check_sub);
			}
		}
		index++;
		len--;
	}
	return (0);
}

/*int	main(void)
{
	//This function locates the first occurence of the null terminated
	// string little in the nul terminated string big
	char	haystack[30] = "AAAAAAAAAAAAA";
	char	needle[30] = "AAAAAAAAAAAAA";
	size_t	num = strlen(haystack);
	char	*result1;
	char	*result2;

	printf("%ld \n",  num);
	result1 = ft_strnstr(haystack, haystack, num);
	result2 = strnstr(haystack, haystack, num);
	printf("Fake     result-->%s\n", result1);
	printf("Expected result-->%s\n", result2);
	return (0);
}*/
