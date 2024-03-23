
#include "../../fdf.h"

static int	count_items(char **items)
{
	int	index;

	index = 0;
	while (items[index] != NULL)
		index++;
	return (index);
}

static void	free_items(char **items)
{
	int	index;

	index = 0;
	while (items[index] != NULL)
	{
		free(items[index]);
		index++;
	}
	free(items);
	items = NULL;
}

t_cor	*extract_items(int row_i, char *line, t_state * state)
{
	t_cor	*pts;
	char	**items;
	int	cols_n;
	int	index;

	index = 0;
	items = ft_split(line, ' ');
	if (items == NULL)
		return (NULL);
	cols_n = count_items(items);
	get_longest_line(cols_n, state);
	pts = (t_cor *) malloc(sizeof(t_cor) * (cols_n));
	if (!pts)
		return (NULL);
	ft_printf("value: ");
	while (items[index] != NULL && index <= (cols_n - 1))
	{
		pts[index].x = (float) index;
		pts[index].y = (float) ft_atoi(items[index]);
		//ft_printf("item: %s\n", items[index]);
		ft_printf(" %d ", (int)pts[index].y);
		get_largest_item(pts[index].y, state);
		pts[index].z = (float) row_i;
		pts[index].id = index;
		index++;
	}
	ft_printf("$\n");
	free_items(items);
	pts[cols_n - 1].id = -1;
	return (pts);
}

t_data_extractor	*create_data_extractor(void)
{
	t_data_extractor	*de;

	de = (t_data_extractor *) malloc (sizeof(t_data_extractor));
	if (!de)
		return (NULL);
	de->extract_items = &extract_items;
	return (de);
}
