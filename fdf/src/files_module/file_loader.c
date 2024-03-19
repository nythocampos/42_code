/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models_loader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:45:15 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/19 16:03:01 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static int	read_file(int file_df, t_state *state, t_imodel_collector *m_collector)
{
	char	*tmp_l;
	int	row_i;
	t_model	*model;

	row_i = 0;
	tmp_l = (char *) malloc(sizeof(char) * 1);
	if (!tmp_l)
		return (0);
	model = (t_model *) malloc(sizeof(t_model) * 1);
	if (!model)
		return (0);
	ft_printf("OK 2.1\n");
	while (tmp_l != NULL)
	{
		free(tmp_l);
		tmp_l = get_next_line(file_df);
		m_collector->collect_data(tmp_l, row_i, model->model_data);
		row_i++;
	}
	free(tmp_l);
	ft_printf("OK 2.2\n");
	set_model(state->models_lst, model);
	ft_printf("Model loaded \n");
	return (1);
}

/*
 * This function opens the file and select
 * a model collector TODO:considering the model format
 */
static int	load_file(char **argv, int n_mod, t_state *state)
{
	int					fd;
	char				*file_path;
	t_imodel_collector	*mod_col;
	int					index;

	index = 0;
	while (++index < n_mod)
	{
		file_path = ft_strjoin(MAPS_PATH, argv[index]);
		fd = open(file_path, O_RDONLY);
		if (fd == -1)
		{
			ft_printf("File %s not found\n", file_path);
			return (0);
		}
		ft_printf("Generating models collector \n");
		mod_col = create_fdf_collector();
		free(file_path);
		ft_printf("Loading file \n");
		if (read_file(fd, state, mod_col) == 0)
			return (0);
		free(mod_col);
		close(fd);
	}
	return (1);
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
