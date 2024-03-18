/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models_loader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:45:15 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/18 19:45:01 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	read_file(int file_df, t_state *state, t_imodel_collector *m_collector)
{
	char	*tmp_l;
	int	row_i;
	t_model	*model;

	row_i = 0;
	tmp_l = (char *) malloc(sizeof(char) * 1);
	if (!tmp_l)
		return ;
	model = (t_model *) malloc(sizeof(t_model) * 1);
	if (!model)
		return ;
	while (tmp_l != NULL)
	{
		free(tmp_l);
		tmp_l = get_next_line(file_df);
		m_collector->collect_data(tmp_l, row_i, m_collector->model);
		row_i++;
	}
	free(tmp_l);
	model->model_data = m_collector->model;
	set_model(state->models_lst, model);
}

/*
 * This function opens the file and select
 * a model collector TODO:considering the model format
 */
void	load_file(char **argv, int n_mod, t_state *state)
{
	int			fd;
	char			*file_path;
	t_imodel_collector	*mod_col;
	int	index;	

	index = 0;
	while (++index < n_mod)
	{
		file_path = ft_strjoin(MAPS_PATH, argv[index]);
		fd = open(file_path, O_RDONLY);
		if (fd == -1)
		{
			ft_printf("File %s not found\n", file_path);
			return ;
		}
		mod_col = create_fdf_collector();
		free(file_path);
		read_file(fd, state, mod_col);
		free(mod_col);
		close(fd);
	}
}

t_ifile_loader	*create_file_loader()
{
	t_ifile_loader	*file_loader;

	file_loader = (t_ifile_loader *) malloc(sizeof(t_ifile_loader) * 1);
	if (!file_loader)
		return (NULL);
	file_loader->load_file = load_file;
	return (file_loader);
}
