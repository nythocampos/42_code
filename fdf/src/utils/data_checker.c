
#include "../../fdf.h"

void	get_longest_line(int cur_line_len, t_state *state)
{
	if (state->models->cols_len < cur_line_len)
		state->models->cols_len = cur_line_len;
}
void	get_largest_item(float item, t_state *state)
{
	if (state->models->val_len < item)
		state->models->val_len = item;
}

void	is_garbage(char *tmp_l)
{
	int	index;

	index = 0;
	if (tmp_l == NULL)
		return ;
	while (tmp_l[index] != '\0')
	{
		if (!ft_isdigit(tmp_l[index]) && (tmp_l[index] != 45) 
			&& (tmp_l[index] != 32) && (tmp_l[index] != '\n'))
		{
			free(tmp_l);
			ft_printf("Invalid data found in the file\n");
			exit (1);
			return ;
		}	
		index++;
	}
}
