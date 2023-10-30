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
	char	*result;
	int		index;
	int		sec_index;

	index = 0;
	sec_index = 0;
	while (buffer[index] != '\n')
		index++;
	result = (char *) malloc((sizeof(char) + 1) * index);
	while (sec_index < index)
	{
		result[sec_index] = buffer[sec_index];
		sec_index++;
	}
	result[sec_index] = '\0';
	return (result);
}

char	read_file()
{
	char			*result;
	size_t			bytes_read;
	void			*buffer;

	buffer = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	result = read_line(buffer);
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static void		*last_pos;
}

#include <fcntl.h>
#include <stdio.h>
int main(void)
{
	int		fd;
	char 	*file_name;

	file_name = "test";
	fd = open(file_name, O_RDONLY);
	//use a loop to test
	printf("%s", get_next_line(fd));
	return (0);
}
