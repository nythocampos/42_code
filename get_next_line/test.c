
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
	int		fd;
	char	*result;

	fd = open("test_file", O_RDONLY);
  //result = "";
	//use a loop to test
  
	printf("1 Result------>%s\n", get_next_line(fd));
	printf("2 Result------>%s\n", get_next_line(fd));
	printf("3 Result------>%s\n", get_next_line(fd));
	printf("4 Result------>%s\n", get_next_line(fd));
	printf("5 Result------>%s\n", get_next_line(fd));
  return (0); 
	while(result != NULL)
	{
		printf("Next_line-->%s\n", result);
		result = get_next_line(fd);
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
