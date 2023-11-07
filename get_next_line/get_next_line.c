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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (ft_strlen(s) < start)
		return (NULL);
	if (len >= ft_strlen(s + start))
		len = (ft_strlen(s + start));
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	ft_memcpy(result, s + start, len);
	result[len] = '\0';
	return (result);
}

/*
	This function reads the buffer until reach a \n 
	then returns the new string
*/
static char	*get_line_content(char *buffer, int *last_nl)
{
	int		index;
	int		sec_index;
	char	*line;

	index = 0;
	sec_index = 0;
	while (buffer[index] != '\n' && buffer[index] != '\0')
		index++;
	if (buffer[index] == '\n')
		index += 1;
	line = (char *) malloc((index + 1)* sizeof(char));
	if (line == 0)
		return (NULL);
	while (sec_index < index)
	{
		line[sec_index] = buffer[sec_index];
		sec_index++;
	}
	// 	line[index + 1] = '\0';
	*last_nl = sec_index;
	line[sec_index] = '\0';
	return (line);
}

static char	*update_buffer(int last_nl, char **buffer)
{
	char	*new_buf;

	new_buf = ft_substr(*buffer, last_nl, ft_strlen(*buffer));
	if (new_buf == NULL)
		new_buf = ft_strdup(*buffer);
	free(*buffer);
	*buffer = 0;
	return (new_buf);
}

/*
 * This Function get a line from a file
 *
 * If the BUFFER_SIZE is not enough to read the entier line
 * then it iterates opening the file and getting the data
 * lot by lot until be able to return the line completed
 *
 */
static int	fill_buffer(int fd, char **buffer)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	temp = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (temp == 0)
		return (-1);
	//temp[0] = '\0';
	//bytes_read = read(fd, temp, BUFFER_SIZE); // -------.
	temp[0] = '\0';
	while (bytes_read > 0 && mod_strchr(temp, '\n') == 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_free(&temp), -1);
		temp[bytes_read] = '\0';
		*buffer = mod_strjoin(*buffer, temp);
	}
	ft_free(&temp);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	char		*new_buf;
	char		*result;
	static char	*buffer = 0;
	static int	last_nl = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = (char *) malloc(1);
		if (buffer == 0)
			return (NULL);
		buffer[0] = '\0';
	}
	if (fill_buffer(fd, &buffer) == -1 || buffer[0] == '\0')
	{
		ft_free(&buffer);
		buffer = 0;
		return (NULL);
	}
	result = get_line_content(buffer, &last_nl);
	if(!result)
	{
		ft_free(&buffer);
		buffer = 0;
		return (NULL);
	}
	new_buf = update_buffer(last_nl, &buffer);
	buffer = ft_strdup(new_buf);
	ft_free(&new_buf);
	return (result);
}
