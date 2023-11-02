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

/*
	This function reads the buffer until reach a \n 
	then returns the new string

	Args:
		buffer (char *): a pointer to the string
	Return:
		result (char *): the new pointer to the line readed
*/
char	*get_line_content(char *buffer)
{
	int		index;
	int		sec_index;
	char	*line;

	index = 0;
	sec_index = 0;
	while (buffer[index] != '\n' && buffer[index] != '\0') //! loop infini 
		index++;
	line = (char *) malloc(index * (sizeof(char) + 1));
	if (line == 0)
		return (NULL);
	while (*buffer != '\n' && *buffer != '\0')
	{ //! continue from last please if buffer cant covert all line
		line[sec_index] = *buffer;
		sec_index++;
		buffer++;
	}
	line[sec_index] = '\0';
  printf("line: %s\n", line);
	return (line);
}

/*
 * This Function get a line from a file
 *
 * If the BUFFER_SIZE is not enough to read the entier line
 * then it iterates opening the file and getting the data
 * lot by lot until be able to return the line completed
 *
 * Args:
 *  fd (int): the file directive of the file to open
 *
 * Return:
 *  total_line (char *): the line to get from the file
 */
char	*find_line(int fd)
{
	static char	*buffer;
	size_t		  bytes_read;
	char		    *total_line;

	//buffer = 0;
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == 0 || fd == -1)
		return (NULL);
  total_line = (char *) malloc(sizeof(char) + 1);
  if (total_line == 0)
    return (NULL);
  total_line[sizeof(char) + 1] = '\0';
  while (*buffer != '\n' && bytes_read != 0)
  {
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read < 0)
    {
      free(buffer);
      return (NULL);
    }
    buffer[bytes_read + 1] = '\0';
    printf("buff: %s\n",buffer);
    total_line = ft_strjoin(total_line, get_line_content(buffer));
  }
	free(buffer);
	//buffer = 0;
	return (total_line);
}

char  *get_next_line(int fd)
{
  char  *result;

  if (fd < -1 || BUFFER_SIZE <= 0)
    return (NULL);

  result = find_line(fd);
  return (result);
}
