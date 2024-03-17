
#include "../../fdf.h"

void	collect_data(t_cor *cor, t_state *state)
{
	// add cor collected to the  t_model
}

t_imodel_collector	*create_models_collector()
{
	t_imodel_collector	*model_collector;

	model_collector = (
			t_imodel_collector *) malloc(
				sizeof(t_imodel_collector) * 1);
	if (!model_collector)
		return (NULL);

	return (model_collector);
}
