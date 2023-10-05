/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:24:59 by antcampo          #+#    #+#             */
/*   Updated: 2023/09/27 18:29:16 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	num = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = -n;
	}
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	ft_putchar_fd(num % 10 + '0', fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s != 0)
		write(fd, s, ft_strlen(s));
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		index;

	str = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (str == 0)
		return (0);
	index = 0;
	while (s[index] != '\0')
	{
		str[index] = s[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}
