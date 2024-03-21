/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_format_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:30:24 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/15 21:09:44 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

/*
 * This function check if line on index-1 position
 * is a number and line on index position is different from
 * a number.
 */
int	on_item(char *line, int index)
{
	if (ft_isdigit(line[index - 1]) && !ft_isdigit(line[index]))
		return (1);
	return (0);
}

int	get_columns_num(char *line)
{
	int	index;
	int	column_num;

	index = 0;
	column_num = 0;
	while (line[index] != '\0')
	{
		if (on_item(line, (index + 1)))
			column_num++;
		index++;
	}
	return (column_num);
}

/*
 * This functoin takes the numbers from the line
 *
 * Args:
 * 	str (char *): line got from the file.
 * 	end (int): the position on the line where
 * 		the numer ends.
 * Parameters:
 * 	num (int): the number got from the line of text.
 * 	str_num (char *): a substring got from str where
 * 	the number is placed.
 *	start (int): the position where the number found starts.
 *
 * Return:
 * 	num (int): the num got from the line and converted to int.
 *
 */
int	get_item_value(char *str, int end)
{
	int		num;
	char	*str_num;
	int		start;
	int		index;

	start = end;
	index = 0;
	num = 0;
	if ((start - 1) < 0 || end == 0)
		return (0);
	while (ft_isdigit(str[start - 1]) || str[start - 1] == 45)
		start--;
	str_num = (char *) malloc(sizeof(char) * ((end - start) + 2));
	if (!str_num)
		return (0);
	while (start <= end)
	{
		str_num[index] = str[start];
		index++;
		start++;
	}
	str_num[index] = '\0';
	num = ft_atoi(str_num);
	free(str_num);
	return (num);
}
