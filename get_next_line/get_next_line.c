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
char	*read_line(char *buffer)
{
	int		index;
	int		sec_index;
	char	*line;

	index = 0;
	sec_index = 0;
	while (buffer[index] != '\n') //! loop infinito 
		index++;
	line = (char *) malloc(index * (sizeof(char) + 1));
	if (line == 0)
		return (NULL);
	while (sec_index < index)
	{ //! continue from last please if buffer cant covert all line
		line[sec_index] = *buffer;
		sec_index++;
		buffer++;
	}
	line[sec_index] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	size_t		bytes_read;
	char		*result;

	//buffer = 0;
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == 0 || fd == -1)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (NULL);
	buffer[bytes_read + 1] = '\0';
	//printf("%s", buffer);
	result = read_line(buffer);
	//free(buffer);
	//buffer = 0;
	return (result);
}

#include <fcntl.h>

int main(void)
{
	int		fd;
	char	*result;

	fd = open("test_file", O_RDONLY);
	//use a loop to test
	printf("%s", get_next_line(fd));
	while(result != NULL)
	{
		result = get_next_line(fd);
		printf("%s", result);
	}
	close(fd);
	return (0);
}

//terminar en nulo el \n