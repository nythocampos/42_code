#include "fdf.h"
#include "libraries/libft_ulti/libft.h"

int get_item_value(char *str, int start)
{
  int num;
  char  *str_num;
  int   end;
  int   index;

  end = start;
  index = 0;
  while (str[end] != ' ')
    end++;
  str_num = malloc((end - start + 1) * sizeof(char));
  while (start < end)
  {
    // fill the str_num from str[start]
    str_num[index] = str[start + index];
    index++;
  }
  num = ft_atoi(str_num);
  return (num);
}

char *convert_line(char *line, int line_num)
{
  char  *converted_line;
  int   index;
  int   column_num;
  int   value;
 
  index = 0;
  column_num = 0;
  while (line[index] == NULL)
  {
    value = get_item_value(line, index);
    if (line[index] == ' ')
      column_num++;
    index++;
  }
  // set a v character
  // set a space
  // set column number as X
  // set a space
  // set line_number as Z
  // set a space
  // set item value as Y
  // set a new line '\n' and do it again with the next item in the line
  // when the end of the line is reached, return the converted_line

  return (converted_line);
}

/*
 * This function loads the content of the file
 */
char	*load_terrain_file(int file_df)
{
  // load file data and convert it to a obj
  int   line_num;
  char  *temp_line;
  char  *converted_line;
  char  *converted_data;
  
  line_num = 0;
  temp_line = 0;
  while (temp_line != NULL)
  {
    temp_line = get_next_line(file_df);
    // convert line
    converted_line = convert_line(temp_line, line_num);
    // append converted line
    converted_data = ft_strjoin(converted_data, converted_line);
    line_num++;
  }
  return (converted_data);
}

/*
* This function is used to choose the process to follow
* considering the type of file to load
*/
void  manage_file_content(char *file_name)
{
	char  *file_extension;
	int	extension_len;

  // if the file loaded
  file_extension = ft_strchr(file_name, 46);
  extension_len = ft_strlen(file_extension);
  if (ft_strncmp(file_extension, ".fdf", extension_len) == 0)
  {
	  // call process to load fdf file
	ft_printf("fdf file loaded");
  }
  else if (ft_strncmp(file_extension, ".obj", extension_len) == 0)
  {
	// call process to load obj file
	ft_printf("obj file loaded");
  }
}
