/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_format_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:30:24 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/05 13:35:31 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	on_item(char *line, int index)
{
	if ((line[index - 1] >= 48 && line[index - 1] <= 57)
		&& (line[index] < 48 || line[index] > 57))
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

int	get_item_value(char *str, int end)
{
	int		num;
	char	*str_num;
	int		start;
	int		index;

	start = end;
	index = 0;
	num = 0;
	while (str[start - 1] >= 48 && str[start - 1] <= 57)
		start--;
	str_num = (char *) malloc(sizeof(char) * (end - start + 1));
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
