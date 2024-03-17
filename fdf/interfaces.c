
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



/*
 * This interface provides a structure
 * that allows the implementation and modification
 * of the state
 */
typedef struct s_istate_manager
{
	void		(*create_state)();
	void		(*clean_state)();
}	t_istate_manager;

typedef struct	s_imlx_manager
{
	void		(*clean_mlx_data)(t_mlx_data *);
	t_mlx_data	*(*create_mlx_data)();
	void		(*refresh_window)(t_mlx_data *);
}	t_imlx_manager;

/*
 * models (t_list): pointer to the first node of the models linked list
 *
 */
typedef struct	s_imodels_manager
{
	t_list		*(*create_models)();
	void		(*clean_models)(t_list *);
	void		(*set_model)(t_list *, t_model *);
	t_list		*(*get_model)(t_list *, int);
}	t_imodels_manager;

