
#include "../../fdf"

s_imodel_updater	*create_model_updater()
{
	s_imodel_updater	*m_updater;

	m_updater = (s_imodel_updater *) malloc(sizeof(s_imodel_updater * 1);
	if (!m_updater)
		return (NULL);
	m_updater->scale_model = scale_model
	m_updater->rotate_model = rotate_model
	m_updater->move_model = move_model
	m_updater->project_model = project_model
	return (s_imodel_updater);
}
