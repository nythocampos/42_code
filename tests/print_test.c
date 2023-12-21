#include <stdio.h>
#include "../lib_ulti/lib.h"

int	main(void)
{
	char ptr[10]= "perro";

	printf("Real: -->%d ", printf("%s \n", str));
	printf("Fake: -->%d ", ft_printf("%s \n", str));

	//printf("Fake size: -->%d \n", ft_printf("%%%%%%"));
	//printf("Real size: -->%d \n\n", printf("%%%%%%"));

	//printf(" Fake size: -->%d \n", ft_printf("%X", -14523));
	//printf(" Real size: -->%d \n\n", printf("%X", -14523));

	// ft_printf("Fake: -->%u \n", -10);
	// printf("Real: -->%u \n", -10);

	//printf(" Fake size: -->%d \n", ft_printf("%%%c", 'x'));
	//printf(" Real size: -->%d \n\n", printf("%%%c", 'x'));	

	//printf(" Fake size: -->%d \n", ft_printf(""));
	//printf(" Real size: -->%d \n", printf(""));

	//printf("FAKE SIZE-> %d \n", ft_printf("%p", NULL));
	//printf("REAL SIZE-> %d \n", printf("%p", NULL));

	printf("REAL SIZE-> %d \n", printf("%d", -10));
	printf("REAL SIZE-> %d \n", printf("%d", -10));
	printf("|--------|\n");
	return (0);
}
