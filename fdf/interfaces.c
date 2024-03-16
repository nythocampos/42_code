
#include "fdf.h"

typedef struct s_ipixels_writer
{
	void	(*write_pixel)(t_mlx_data,int,int,int);
}	t_ipixels_writer;

typedef struct	s_imodel_updater
{
	void	(*scale_model)(t_model *,int,int,int);
	void	(*rotate_model)(t_model *,int,int,int);
	void	(*move_model)(t_model *,int,int,int);
}	s_imodel_updater;

typedef struct s_imodel_collector
{
	void	(collect_data)(t_cor *, t_istate *);
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
typedef struct s_istate
{
	t_state		*state;
	void		(*create_state)();
	void		(*clean_state)();
	t_mlx_data	*(*get_mlx_data)();
	t_models	*(*get_models)();
}	t_istate;

typedef struct	s_imodels
{
	t_list		*models;
	void		(*create_models)();
	t_model		*(*get_model_by_id)(int);
	void		(*set_model)(t_model *);
}	t_imodels;

