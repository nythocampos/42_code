
#include "../../fdf.h"

// TODO: update this code
t_state	*create_state()
{
	t_state	*state;

	ft_printf("Models loaded: %d\n", models_num);
	state = (t_state *) malloc(sizeof(t_state) * 1);
	if (!state)
		return (NULL);
	state->mlx_data = initialize_win();
	if (state->mlx_data == NULL)
	{
		ft_printf("[INITIALIZING WINDOW]\n");
		// end_program
		return (NULL);
	}
	state->models = import_model(argv);
	if (state->models == NULL)
	{
		ft_printf("[IMPORTING MODELS]\n");
		// end_program
		return (NULL);
	}
	return (state);
}

void	clean_state(t_state *state)
{
	free(state);
}

istate	*create_state()
{
	t_istate	*istate;

	istate = (t_istate *) malloc(sizeof(t_istate) * 1);
	if (!istate)
		return (NULL);
	istate->create_state = create_state;
	istate->clean_state = &clean_state;
}
