/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:09:10 by antcampo          #+#    #+#             */
/*   Updated: 2023/10/05 18:12:07 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		index;
	char	*a;

	index = 0;
	a = (char *) dst;
	if (dst == (void *) '\0' && src == (void *) '\0')
		return (dst);
	while (n != 0)
	{
		a[index] = *(char *)src;
		n--;
		index++;
		src++;
	}
	dst = a;
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;

	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len >= ft_strlen(s + start) || len < 0)
		len = (ft_strlen(s + start));
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	ft_memcpy(result, s + start, len);
	result[len] = '\0';
	return (result);
}

size_t	ft_strlen(const char *s)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}

void	select_writer(char type, va_list valist, int *len)
{
	if (type == 'c')
		ft_putchar_fd((char) va_arg(valist, int), 1);
	if (type == 's')
		ft_putstr_fd((char *) va_arg(valist, int), 1);
	//if (type == 'p')
	//	ft_putchar_fd((void *) va_arg(valist, void *), 1);
	if (type == 'd')
		ft_putnbr_fd((int) va_arg(valist, int), 1);
	if (type == 'i')
		ft_putnbr_fd((int) va_arg(valist, int), 1);
	if (type == 'u')
		ft_putnbr_fd((int) va_arg(valist, int), 1);
	//if (type == 'x')
	//	ft_putchar_fd((int) va_arg(valist, int), 1);
	//if (type == 'X')
	//	ft_putchar_fd((int) va_arg(valist, int), 1);
	if (type == '%')
		ft_putchar_fd('%', 1);
}
