
#include "../../fdf.h"

/*
 * TODO: move this function to the window module
 *
 */
static t_mlx_data	*initialize_win(void)
{
	t_mlx_data	*mlx_data;

	mlx_data = (t_mlx_data *) malloc(sizeof(t_mlx_data) * 1);
	if (!mlx_data)
		return (NULL);
	mlx_data->mlx = mlx_init();
	set_window(mlx_data, "FDF");
	return (mlx_data);
}

t_state	*initialize_state(int n_mod, char **argv)
{
	t_state	*state;

	state = (t_state *) malloc(sizeof(t_state) * 1);
	if (!state)
		return (NULL);
	state->models = import_models(n_mod, argv);
	if (state->models == NULL)
	{
		ft_printf("[IMPORTING MODELS]\n");
		free(state);
		return (NULL);
	}
	state->mlx_data = initialize_win();
	if (state->mlx_data == NULL)
	{
		ft_printf("[INITIALIZING WINDOW]\n");
		free(state->models);
		free(state);
		return (NULL);
	}
	return (state);
}

