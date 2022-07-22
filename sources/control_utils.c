/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:13:21 by mbishop-          #+#    #+#             */
/*   Updated: 2022/06/27 14:13:24 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	reset_camera(int key, t_main *main)
{
	int			cam_width;
	int			cam_height;

	if (key == KEY_R)
	{
		cam_width = (WIN_WIDTH / main->map->columns) / 2;
		cam_height = (WIN_HEIGHT / main->map->rows) / 2;
		if (cam_width < cam_height)
			main->cam->zoom = cam_width;
		else
			main->cam->zoom = cam_height;
		if (main->cam->zoom < 1)
			main->cam->zoom = 1;
		main->cam->x_rot = 0;
		main->cam->y_rot = 0;
		main->cam->z_rot = 0;
		main->cam->x_trans = 0;
		main->cam->y_trans = 0;
		main->cam->z_divisor = 2;
	}
	draw(main->map, main->cam, main->mlx_inst, main->image);
}

int	close_window(t_main *main)
{
	mlx_destroy_window(main->mlx_inst->mlx, main->mlx_inst->mlx_win);
	free(main->cam);
	free(main->image);
	free_array((char **)main->map->point);
	free(main->map);
	free(main->mlx_inst);
	free(main);
	exit (0);
}
