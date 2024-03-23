
#include "../../fdf.h"

/*
 * This function checks if the
 * character could be a part of a
 * valid data in decimal or hexadecimal.
 *
 */
static int	is_valid(char c)
{
	if (ft_isdigit(c)
		|| c == '-' 
		|| (ft_tolower(c) >= 'a'
			&& ft_tolower(c) <= 'f'))
		return (1);
	return (0);	
}

static int	count_items(char **items)
{
	int	index;

	index = 0;
	while (items[index] != NULL)
		index++;
	return (index);
}

t_cor	*extract_items(int row_i, char *line)
{
	t_cor	*pts;
	char	**items;
	int	cols_n;
	int	index;

	index = 0;
	items = ft_split(line, ' ');
	cols_n = count_items(items);
	pts = (t_cor *) malloc(sizeof(t_cor) * (cols_n));
	if (!pts)
		return (NULL);
	while (items[index] != NULL)
	{
		pts[col_i].x = (float) index;
		pts[index]->y = (float) ft_atoi(items[index]);
		get_largest_item(pts[col_i].y, state);
		pts[col_i].z = (float) row_i;
		pts[col_i].id = index;
		index++;
	}
}

t_data_extractor	*create_data_extractor()
{
	t_data_extractor	*de;

	de = (t_data_extractor *) malloc (sizeof(t_data_extractor));
	if (!de)
		return (NULL);
	de->extract_items = &extract_items;
	return (de);
}
