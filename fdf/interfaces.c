
#include "fdf.h"

typedef struct	s_data_extractor
{
	t_cor	*(*extract_items)(int, char *);
}	t_data_extractor;

