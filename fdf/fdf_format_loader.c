/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_loader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:29:19 by antcampo          #+#    #+#             */
/*   Updated: 2024/01/19 21:25:47 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int get_item_value(char *str, int start)
{
  int   num;
  char  *str_num;
  int   end;
  int   index;

  end = start;
  index = 0;
  while (str[end] != ' ')
    end++;
  str_num = (char *) malloc((end - start + 1) * sizeof(char));
  while (start < end)
  {
    str_num[index] = str[start + index];
    index++;
  }
  num = ft_atoi(str_num);
  free(str_num);
  return (num);
}

static char *convert_line(char *line, int line_num)
{
  char  *res_line;
  int   index;
  int   column_num;
  int   item_value;
 

  index = 0;
  column_num = 0;
  // set a v character
  // set a space
  res_line = ft_strdup("v ");
  while (line[index] == '\0')
  {
    // set column number as X
    res_line = ft_strjoin(res_line, ft_itoa(column_num));
    // set a space
    res_line = ft_strjoin(res_line, " ");
    // set line_number as Z
    // set a space
    item_value = get_item_value(line, index);
    res_line = ft_strjoin(res_line, ft_itoa(item_value));
    res_line = ft_strjoin(res_line, " ");
    // set item value as Y
    // set a new line '\n' and do it again with the next item in the line
    res_line = ft_strjoin(res_line, ft_itoa(line_num));
    res_line = ft_strjoin(res_line, "\n");
    if (line[index] == ' ')
      column_num++;
    index++;
  } 
  // when the end of the line is reached, return the converted_line

  return (res_line);
}

/*
 * This function loads the content of the file
 */
char	*load_terrain_model(int file_df)
{
	// load file data and convert it to a obj
	int   line_num;
	char  *temp_line;
	char  *converted_line;
	char  *converted_data;

	line_num = 0;
	temp_line = (char *) malloc(1);
	temp_line[0] = '\0';
	while (temp_line != NULL)
	{
		free(temp_line);
		temp_line = get_next_line(file_df);
		// convert line
		converted_line = convert_line(temp_line, line_num);
		// append converted line
		converted_data = ft_strjoin(converted_data, converted_line);
		line_num++;
	}
	return (converted_data);
}


