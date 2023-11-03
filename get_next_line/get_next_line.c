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
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif
#include "get_next_line.h"
#include <stdio.h>

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
  char                    *result;

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
    if (buffer[sec_index] == '\n')
      *flag = 1;
	}
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
static char	*find_line(int fd, char *buffer)
{
	size_t  bytes_read;
	char	  *total_line;
  char    *line;
  int     flag;

  bytes_read = 1;
  flag = 0;
  total_line = (char *) malloc(1);
  if (total_line == 0)
    return (NULL);
  total_line[0] = 0;
  while (flag == 0 && bytes_read != 0)
  {
    if (*buffer == '\0')
      bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read <= 0)
    {
      free(total_line);
      return (NULL);
    }
    buffer[bytes_read] = '\0';
    line = get_line_content(buffer, &flag);
    total_line = mod_strjoin(total_line, line);
  }
  free(line);
	return (total_line);
}

char  *get_next_line(int fd)
{
  char  *result;  
	static char	*buffer;

  //buffer = 0;
  result = 0;
  if (fd < 0 || BUFFER_SIZE <= 0)
    return (NULL);
  if (!buffer)
  	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == 0)
		return (NULL);
  printf("Initial_Buffer-->%s\n",buffer);
  result = find_line(fd, buffer);
  buffer = ft_substr(buffer, ft_strlen(result), ft_strlen(buffer));
  printf("Result_Buffer->%s\n",buffer);
  //free(buffer);
  return (result);
}
