
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
	int		fd;
	char	*result;

	fd = open("test_file", O_RDONLY);
	//use a loop to test
	printf("Result------>%s\n", get_next_line(fd));
	printf("Result------>%s\n", get_next_line(fd));
  return (0); 
	while(result != NULL)
	{
		result = get_next_line(fd);
		printf("%s\n", result);
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
