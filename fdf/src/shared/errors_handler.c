
#include "../../fdf.h"


static void	write_mess(char *location, char *err)
{
	ft_printf("[%s]: %s\n", location, err);
}

void	*err_ret_null(char *location, char *err)
{
	write_mess(location, err);
	return (NULL);
}

void	*err_ret_num(char *location, char *err)
{	
	write_mess(location, err); 
	return (NULL);
}
