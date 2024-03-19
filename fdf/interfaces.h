
#include "fdf.h"

typedef struct	s_ifile_loader
{
	int	(*load_file)(char **, int, t_state *);
}	t_ifile_loader;

typedef struct s_ipixels_writer
{
	void	(*set_pixel)(t_img *, int, int, int);
	void	(*write_pixel)(t_state *, t_cor *, int);
}	t_ipixels_writer;

typedef struct s_iaxes_updater
{
	void	(*scale_axes)(t_cor *,float,float,float);
	void	(*rotate_axes)(t_cor *,float,float,float);
	void	(*move_axes)(t_cor *,float,float,float);
	void	(*project_axes)(t_cor *); // add a way to scale the projection
	void	(*scale_projection_axes)(t_cor *,float, float, float);
}	t_iaxes_updater;

typedef struct	s_imodel_updater
{
	void	(*scale_model)(t_list *, float, float, float);
	void	(*rotate_model)(t_list *, float, float, float);
	void	(*move_model)(t_list *, float, float, float);
	void	(*project_model)(t_list *);
	void	(*scale_model_projection)(t_list *,float, float, float)
}	t_imodel_updater;

typedef struct s_imatrix_creator
{
	float	*(*gen_rot_mtx_x)(float);
	float	*(*gen_rot_mtx_y)(float);
	float	*(*gen_rot_mtx_z)(float);
	float	*(*get_pro_mtx)(void);
}	t_imatrix_creator;

/*
 * This interface is used to create different
 * types of model collectors
 */
typedef struct s_imodel_collector
{
	t_list	*model;
	int	(*collect_data)(char *, int, t_list **);
}	t_imodel_collector;

typedef struct	s_imodel_printer
{
	void	(*print_model)(t_list *, t_ipixels_writer *, t_state *state);
}	t_imodel_printer;
