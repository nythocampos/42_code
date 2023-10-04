
#include <stdio.h>
#include <stdarg.h>

void	check_args(int index,...)
{
	va_list	valist;
	int		current_value;

	va_start(valist, index);
	while (current_value != '\0')
   	{
		current_value = va_arg(valist, int);	
		printf("current_value:%d\n", current_value);
	}
	va_end(valist);	
}

int	main(void)
{
	check_args(4, 1,2,3,4);
	return (0);
}
