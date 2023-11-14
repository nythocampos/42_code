/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:04:02 by antcampo          #+#    #+#             */
/*   Updated: 2023/11/14 12:17:20 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *args, ...)
{
	int		index;
	int		total_len;
	int		args_num;
	va_list	valist;

	index = 0;
	args_num = 0;
	va_start(valist, args);
	while (args[index] != '\0')
	{
		if (args[index] != '%')
			ft_putchar(args[index], &total_len);
		else if (args[index] == '%')
		{
			if (args[index + 1] == '\0')
				return (0);
			select_writer(args[index + 1], valist, &total_len);
			if (total_len == -1)
				return (-1);
			index++;
			args_num++;
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
	char ptr[10]= "perro";

	// printf("Real: -->%d ", printf("%s \n", str));
	// printf("Fake: -->%d ", ft_printf("%s \n", str));

	//printf("Fake size: -->%d \n", ft_printf("%%%%%%"));
	//printf("Real size: -->%d \n\n", printf("%%%%%%"));

	//printf(" Fake size: -->%d \n", ft_printf("%X", 4779));
	//printf(" Real size: -->%d \n\n", printf("%X", 4779));

	// ft_printf("Fake: -->%u \n", -10);
	// printf("Real: -->%u \n", -10);

	printf(" Fake size: -->%d \n", ft_printf("%%%c", 'x'));
	printf(" Real size: -->%d \n\n", printf("%%%c", 'x'));	

	printf(" Fake size: -->%d \n", ft_printf(""));
	printf(" Real size: -->%d \n", printf(""));

	ft_printf("Fake: -->%p \n", ptr);
	printf("Real: -->%p \n", ptr);
	printf("|--------|\n");
	return (0);
}
