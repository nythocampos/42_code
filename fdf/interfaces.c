
#include "fdf.h"

typedef struct	s_ifile_loader
{
	void	(*load_file)(char *, t_state *);
}	t_ifile_loader;

typedef struct s_ipixels_writer
{
	void	(*write_pixel)(t_mlx_data, int, int, int);
}	t_ipixels_writer;

typedef struct	s_imodel_updater
{
	void	(*scale_model)(t_model *, int, int, int);
	void	(*rotate_model)(t_model *, int, int, int);
	void	(*move_model)(t_model *, int, int, int);
	void	(*project_model)(t_model *);
}	s_imodel_updater;

/*
 * This interface is used to create different
 * types of model collectors
 */
typedef struct s_imodel_collector
{
	t_list	*model;

	void	(collect_data)(char *, int);
}	t_imodel_collector;

typedef struct	s_imodel_printer
{
	void	(*print_model)(t_model *, t_ipixels_writer *);
}	t_imodel_printer;
