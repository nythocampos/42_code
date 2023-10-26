/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:04:02 by antcampo          #+#    #+#             */
/*   Updated: 2023/10/26 13:17:15 by antcampo         ###   ########.fr       */
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
	int		total_len; //num returned by printf with the total len of the function
	int		start;
	va_list	valist;

	index = 0;
	start = 0;
	va_start(valist, args);
	while (args[index] != '\0')
	{
		if (args[index] != '%')
			ft_putchar(args[index]);
		if (args[index] == '%')
		{
			if (args[index + 1] != '\0') // What if the % is at the end of the string?
			{
				select_writer(args[index + 1], valist, &total_len);
				index++;
			}
		}
		index++;
	}
	va_end(valist);
	return (total_len);
}

#include <stdio.h>
int	main(void)
{
	//ft_printf("Fake: -->%d\n", 5);
	//printf("Real: -->%d\n", 5);
	char str[10]= "perro";
	void *ptr = &str;

	// ft_printf("Fake: -->%d | %s\n", 5, str);
	// printf("Real: -->%d | %s\n", 5, str);

	// ft_printf("Fake: -->%X \n", 4779);
	// printf("Real: -->%X \n", 4779);

	// ft_printf("Fake: -->%u \n", -10);
	// printf("Real: -->%u \n", -10);

	ft_printf("Fake: -->%p \n", ptr);
	printf("Real: -->%p \n", ptr);
	printf("|--------|");
	return (0);
}
