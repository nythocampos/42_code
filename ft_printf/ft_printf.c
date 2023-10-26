/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:04:02 by antcampo          #+#    #+#             */
/*   Updated: 2023/10/26 15:32:58 by antcampo         ###   ########.fr       */
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
	while (args[index] != '\0' || total_len == -1)
	{
		if (args[index] != '%')
			ft_putchar(args[index]);
		if (args[index] == '%')
		{
			if (args[index + 1] != '\0')
			{
				select_writer(args[index + 1], valist, &total_len);
				index++;
				args_num++;
			}
		}
		index++;
	}
	va_end(valist);
	return (total_len + index - (args_num * 2));
}

// #include <stdio.h>
// int	main(void)
// {
// 	//ft_printf("Fake: -->%d\n", 5);
// 	//printf("Real: -->%d\n", 5);
// 	char str[10]= "perro";

// 	printf("Real: -->%d ", printf("%s \n", str));
// 	printf("Fake: -->%d ", ft_printf("%s \n", str));

// 	// ft_printf("Fake: -->%X \n", 4779);
// 	// printf("Real: -->%X \n", 4779);

// 	// ft_printf("Fake: -->%u \n", -10);
// 	// printf("Real: -->%u \n", -10);

// 	// ft_printf("Fake: -->%p \n", ptr);
// 	// printf("Real: -->%p \n", ptr);
// 	printf("\n|--------|");
// 	return (0);
// }
