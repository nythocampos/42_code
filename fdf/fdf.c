/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:50:30 by antcampo          #+#    #+#             */
/*   Updated: 2024/03/20 16:13:34 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	test()
{
	int		fd;
	char	*tmp_l;
	
	fd = open("./models/42.fdf", O_RDONLY);
	if (fd == -1)
	{
		ft_printf("File not found\n");
		return (0);
	}
	tmp_l = (char *) malloc(sizeof(char) * 1);
	if (!tmp_l)
		return (0);
	while (tmp_l != NULL)
	{
		free(tmp_l);
		tmp_l = get_next_line(fd);
		ft_printf("LINE: %s\n",tmp_l);
	}
	free(tmp_l);
	close(fd);
	return 0;
}

int	main(int argc, char *argv[])
{
	t_state		*state;

	//test();
	if (argc != 2)
		return (0);
	state = initialize_state(argv);	
	if (state == NULL || state->models == NULL) // check models and mlx
	{
		ft_printf("Error generating the state\n");
		end_program(state);
		return (0);
	}
	set_events(state);
	mlx_loop(state->mlx_data->mlx);
}

