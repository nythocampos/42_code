/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_builder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:12:50 by antcampo          #+#    #+#             */
/*   Updated: 2024/01/18 19:51:00 by antcampo         ###   ########.fr       */
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

s_frame *build_frame(int file_df)
{
  int   	line_num;
  s_frame 	frame;
  
  line_num = 0;
  while (temp_line != NULL)
  {
    free(temp_line);
    temp_line = get_next_line(file_df);
    line_num++;
  }
  return (frame);
}
