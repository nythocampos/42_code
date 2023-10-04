/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:04:02 by antcampo          #+#    #+#             */
/*   Updated: 2023/10/04 14:26:21 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int	count_args(char *s)
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
	va_start(valist, count_args(args));
	while (args[index] != '\0')
	{
		if (args[index] == '%')
		{
			//print last string as string
			ft_putstr_fd(ft_substr(args, start, (index - start)), 1);
			start = index;
			result += (index - start);
			// call facade function: facade(args[index + 1], arg[num])
			//pass index + 1 and arg num has argument 
			if (args[index + 1] != '\0')
				select_writer(args[index + 1], valist, &result); //TODO: replace this args[num]
		}
		index++;
	}
	va_end(valist);
	return (0);
}
//puntero
