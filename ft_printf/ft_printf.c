/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:04:02 by antcampo          #+#    #+#             */
/*   Updated: 2023/10/05 15:39:15 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	count_args(char const *s)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (s[index] != '\0')
	{
		if (s[index] == '%')
			count++;
	}
	return (count);
}

int	ft_printf(char const *args, ...)
{
	int		index;
	int		result; //num returned by printf with the total len of the function
	int		start;
	va_list	valist;

	index = 0;
	start = 0;
	va_start(valist, args);
	while (args[index] != '\0')
	{
		if (args[index] == '%')
		{
			ft_putstr_fd(ft_substr(args, start, (index - start)), 1);
			start = index;
			result += (index - start);

			result++;
			//if (args[index + 1] != '\0')
			//	select_writer(args[index + 1], valist, &result);
		}
		index++;
	}
	va_end(valist);
	return (0);
}

#include <stdio.h>
int	main(void)
{
	ft_printf("Fake: -->%d", 5);
	printf("Real: -->%d", 5);
	return (0);
}