/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:01:00 by antcampo          #+#    #+#             */
/*   Updated: 2023/10/30 16:02:36 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
  char  *result;

  if (ft_strlen(s) < start)
          return (ft_strdup(""));
  if (len >= ft_strlen(s + start) || len < 0)
          len = (ft_strlen(s + start));
  result = (char *)malloc(sizeof(char) * (len + 1));
  if (!result)
          return (0);
  ft_memcpy(result, s + start, len);
  result[len] = '\0';
  return (result);
}

/*
	This function reads the buffer until reach a \n 
	then returns the new string
*/
static char	*get_line_content(char *buffer, int *flag)
{
	int		index;//re use this variable
	int		sec_index;
	char	*line;

	index = 0;
	sec_index = 0;
	while (buffer[index] != '\n' && buffer[index] != '\0')
		index++;
	line = (char *) malloc(index * (sizeof(char) + 1));
	if (line == 0)
		return (NULL);
	while (buffer[sec_index] != '\n' && buffer[sec_index] != '\0')
	{
		line[sec_index] = buffer[sec_index];
		sec_index++;
	}
  *flag = sec_index + 1;
	line[sec_index] = '\0';
	return (line);
}

/*
 * This Function get a line from a file
 *
 * If the BUFFER_SIZE is not enough to read the entier line
 * then it iterates opening the file and getting the data
 * lot by lot until be able to return the line completed
 *
 */
static char	*update_buffer(int fd, char **buffer, int last_nl)
{
	size_t  bytes_read;
  char    *temp;
  char    *new_buf;

  bytes_read = 1;
  if (!*buffer)
  {
    *buffer = (char *) malloc(1);
    if (*buffer == 0)
      return (NULL);
    temp = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (temp == 0)
      return (NULL);
    while (bytes_read != 0)
    {
      bytes_read = read(fd, temp, BUFFER_SIZE);
      if (bytes_read < 0)
      {
        free(temp);
        return (NULL);
      }
      temp[bytes_read] = '\0';//use dup for mod_strjoin?
      *buffer = mod_strjoin(*buffer, temp);// what happent to the last *buffer
    }
  }
  free(temp);
  new_buf = ft_substr(*buffer, last_nl, ft_strlen(*buffer));
  //new_buf = ft_strdup("line\nline2\n");
  free(*buffer);
  if (new_buf == 0)
    return (NULL);
	return (new_buf);
}

char  *get_next_line(int fd)
{
  char        *new_buf;  
	static char	*buffer = 0;
  static int  last_nl = 0;

  if (fd < 0 || BUFFER_SIZE <= 0)
    return (NULL);
  printf(" |-----|\n");
  printf("Initial_Buffer-->%s\n",buffer);
  printf("last_nl %d\n", last_nl);
  new_buf = update_buffer(fd, &buffer, last_nl);
  buffer = ft_strdup(new_buf);
  printf("Result_Buffer->%s\n",buffer);
  //free(buffer);
  return (get_line_content(new_buf, &last_nl));
  //return ("");
}
