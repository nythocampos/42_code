#include <stdio.h>
#include "libft.h"

int	asser_equals(char *fun_name, int a, int b)
{
	printf("%s --->", fun_name);
	if (a == b)
	{
		printf("[OK] \n");
		return (1);
	}
	printf("[KO] \n");
	return (0);
}

int	assert_true(char *fun_name, int a)
{
	printf("%s --->", fun_name);
	if (a == 1)
	{
		printf("[OK] \n");
		return (1);
	}
	printf("[KO] \n");
	return (0);
}

int	assert_false(char *fun_name, int a)
{
	if (a == 0)
	{
		printf("[OK] \n");
		return (1);
	}
	printf("[KO] \n");
	return (0);
}

int	assert_null(char *fun_name, int *ptr)
{
	printf("%s --->", fun_name);
	if (ptr[0] == '\0')
	{
		printf("[OK] \n");
		return (1);
	}
	printf("[KO] \n");
	return (0);
}

int	assert_array_equals(char *fun_name, int *array, int *array2)
{
	int	index;

	index = 0;
	printf("%s --->", fun_name);
	while (array[index] != '\0' && array2[index] != '\0')
	{
		if (sizeof(array) != sizeof(array2))
			break ;
		if (array[index] != array2[index])
			break ;
		if (sizeof(array) == index)
		{
			printf("[OK] \n");
			return (1);
		}
		index++;
	}
	printf("[KO] \n");
	return (0);
}
