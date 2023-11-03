
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*result;

	fd = open("./files/42_no_nl", O_RDONLY);
	//fd = open("./files/multiple_line_with_nl", O_RDONLY);
	//fd = open("./files/multiple_nlx5", O_RDONLY);
  	result = "";
	//use a loop to test
  	/*
	printf("1 Result------>%s\n", get_next_line(fd));
	printf("2 Result------>%s\n", get_next_line(fd));
	printf("3 Result------>%s\n", get_next_line(fd));
	printf("4 Result------>%s\n", get_next_line(fd));
	printf("5 Result------>%s\n", get_next_line(fd));
  	return (0);*/
	while (result != NULL)
	{
		result = get_next_line(fd);
		printf("Next_line-->%s", result);
	}
	free(result);
	close(fd);
	return (0);
}

/*int	main(void)
{
	printf("%d", BUFFER_SIZE);
	return (0);
}*/
