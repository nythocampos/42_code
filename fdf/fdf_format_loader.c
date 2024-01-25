/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_loader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:29:19 by antcampo          #+#    #+#             */
/*   Updated: 2024/01/25 20:19:57 by antcampo         ###   ########.fr       */
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
	while (str[end + 1] != ' ' && str[end] != '\0')
		end++;
	str_num = (char *) malloc((end - start + 1) * sizeof(char));
	if (str_num == NULL)
		return (0);
	while (start < end)
	{
		str_num[index] = str[start + index];
		index++;
	}
	str_num[index] = '\0';
	num = ft_atoi(str_num);
	free(str_num);
	return (num);
}

static void	convert_line(char *line, int line_num)
{
  char  *res_line;
  int   index;
  int   column_num;
  int   item_value;
 

  index = 1;
  column_num = 0;
  // set a v character
  // set a space
 
  //res_line = ft_strdup("v ");
  if (line == NULL)
	  return;
  while (line[index] != '\0')
  {
    // set column number as X
	
    //res_line = ft_strjoin(res_line, ft_itoa(column_num));

    // set a space
	
    //res_line = ft_strjoin(res_line, " ");

    // set line_number as Z
    // set a space

	// detect number area
	// increment the number of column
	if ((line[index - 1] >= 48 && line[index - 1] <= 57) && 
		(line[index] < 48 || line[index] > 57))
	{
    	//item_value = get_item_value(line, index);
		column_num++;
		ft_printf("column: %d value: %d \n", column_num, item_value);
	}
    /*res_line = ft_strjoin(res_line, ft_itoa(item_value));
    res_line = ft_strjoin(res_line, " ");*/

    // set item value as Y
    // set a new line '\n' and do it again with the next item in the line
	
    /*res_line = ft_strjoin(res_line, ft_itoa(line_num));
    res_line = ft_strjoin(res_line, "\n");*/

    index++;
  } 
  // when the end of the line is reached, return the converted_line

}

/*
 * This function loads the content of the file
 */
struct s_element	load_terrain_model(int file_df)
{
	// load file data and convert it to a obj
	int   line_num;
	char  *temp_line;
	struct s_element  model;

	line_num = 0;
	temp_line = (char *) malloc(1);
	if (temp_line == NULL)
		return (model);
	temp_line[0] = '\0';
	while (temp_line != NULL)
	{
		free(temp_line);
		temp_line = get_next_line(file_df);
		//ft_printf("%s \n", temp_line);
		convert_line(temp_line, line_num);
		// append converted line	
		line_num++;
	}
	return (model);
}

