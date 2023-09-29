/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:15:54 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/28 03:44:16 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
This function copies len bytes from string src to a temporal buffer
and from the buffer to string dst. This avoids the overlaps.
*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char		*a;
	unsigned char			*b;

	if ((dst == (void *) '\0' && src == (void *) '\0'))
		return (dst);
	if (dst > src)
	{
		a = src + len;
		b = dst + len;
		while (len-- > 0)
			*--b = *--a;
	}
	else
	{
		a = src;
		b = dst;
		while (len-- > 0)
			*b++ = *a++;
	}
	return (dst);
}

/*int	main(void)
{
	char	src[30] = "lorem ipsum dolor sit amet";
	char	src1[30] = "lorem ipsum dolor sit amet";
    char 	*str;
    char 	*str1;
	int		num;

	str = src;
	str1 = src1;
	num = 5;
    str = memmove(src + 1 , "consectetur", num);
    printf("Real->%s\n", str); // Imprimirá "Hello, world!"
    str1 = ft_memmove(src1 + 1 , "consectetur", num);
    printf("Fake->%s\n", str1); // Imprimirá "Hello, world!"
    return 0;
}*/
// void	*ft_memmove(void *dst, const void *src, size_t len)
// {
// 	char	*a;
// 	char	*b;
// 	char	temp;

// 	if ((dst == (void *) '\0' && src == (void *) '\0'))
// 		return (dst);
// 	if (dst > src)
// 	{
// 		a = (char *)src + len;
// 		b = (char *)dst + len;
// 		while (len-- >= 0)
// 		{
// 			if (b == src)
// 				break ;
// 			temp = *a--;
// 			*b-- = temp;
// 		}
// 	}
// 	else 
// 	{
// 		a = (char *)src;
// 		b = (char *)dst;
// 		while (len-- > 0)
// 		{
// 			temp = *a++;
// 			*b++ = temp;
// 		}
// 	}
// 	return (dst);
// }