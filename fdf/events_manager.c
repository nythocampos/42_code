/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcampo <antcampo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:55:03 by antcampo          #+#    #+#             */
/*   Updated: 2023/12/29 20:03:52 by antcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// TO CONCIDER: Use an interface to controler the keys pressed
int handle_keys(int key_num, t_mlx_data *data)
{
  // ESC or X button are pressed
  if (key_num == XK_Escape)
  {
    ft_printf("ESC pressed");
    end_program(data);
  }
  //if (key_num == )
  return (0);
}

void	set_events(t_mlx_data *data)
{
	mlx_key_hook(data->win_ptr,  handle_keys, &data);
}
