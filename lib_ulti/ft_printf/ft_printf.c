/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:04:02 by antcampo          #+#    #+#             */
/*   Updated: 2023/11/17 08:28:08 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *args, ...)
{
	int		index;
	int		total_len;
	va_list	valist;

	index = 0;
	total_len = 0;
	va_start(valist, args);
	while (args[index] != '\0')
	{
		if (args[index] != '%')
			ft_putchar(args[index], &total_len);
		else if (args[index] == '%')
		{
			if (args[index + 1] == '\0')
				return (total_len);
			select_writer(args[index + 1], valist, &total_len);
			index++;
		}
		if (total_len == -1)
			return (-1);
		index++;
	}
	va_end(valist);
	return (total_len);
}

//TODO: handle the errors checking just the total_len instead returning -1
//! error in 2th write 
// ? to  check
// it looks like it must not work with the following examples
// "", NULL, (void *)-14523
//"%pp%p%p", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX
/*#include <stdio.h>
int	main(void)
{
	//char ptr[10]= "perro";

	// printf("Real: -->%d ", printf("%s \n", str));
	// printf("Fake: -->%d ", ft_printf("%s \n", str));

	//printf("Fake size: -->%d \n", ft_printf("%%%%%%"));
	//printf("Real size: -->%d \n\n", printf("%%%%%%"));

	//printf(" Fake size: -->%d \n", ft_printf("%X", -14523));
	//printf(" Real size: -->%d \n\n", printf("%X", -14523));

	// ft_printf("Fake: -->%u \n", -10);
	// printf("Real: -->%u \n", -10);

	//printf(" Fake size: -->%d \n", ft_printf("%%%c", 'x'));
	//printf(" Real size: -->%d \n\n", printf("%%%c", 'x'));	

	//printf(" Fake size: -->%d \n", ft_printf(""));
	//printf(" Real size: -->%d \n", printf(""));

	//printf("FAKE SIZE-> %d \n", ft_printf("%p", NULL));
	//printf("REAL SIZE-> %d \n", printf("%p", NULL));

	printf("REAL SIZE-> %d \n", printf("%d", -10));
	printf("REAL SIZE-> %d \n", printf("%d", -10));
	printf("|--------|\n");
	return (0);
}*/
