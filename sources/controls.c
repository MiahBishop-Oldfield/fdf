/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:13:35 by mbishop-          #+#    #+#             */
/*   Updated: 2022/06/27 14:13:38 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	zoom(int key, t_main *main)
{
	if (key == KEY_E)
		main->cam->zoom++;
	if (key == KEY_D)
		main->cam->zoom--;
	if (main->cam->zoom < 1)
		main->cam->zoom = 1;
	draw(main->map, main->cam, main->mlx_inst, main->image);
}

void	rotate(int key, t_main *main)
{
	if (key == KEY_Q)
		main->cam->x_rot -= 0.05;
	if (key == KEY_W)
		main->cam->x_rot += 0.05;
	if (key == KEY_A)
		main->cam->y_rot -= 0.05;
	if (key == KEY_S)
		main->cam->y_rot += 0.05;
	if (key == KEY_Z)
		main->cam->z_rot -= 0.05;
	if (key == KEY_X)
		main->cam->z_rot += 0.05;
	draw(main->map, main->cam, main->mlx_inst, main->image);
}

void	change_height(int key, t_main *main)
{
	if (key == KEY_F)
		main->cam->z_divisor -= 0.1;
	if (main->cam->z_divisor < 0.1)
		main->cam->z_divisor = 0.1;
	if (key == KEY_V)
		main->cam->z_divisor += 0.1;
	if (main->cam->z_divisor > 10)
		main->cam->z_divisor = 10;
	draw(main->map, main->cam, main->mlx_inst, main->image);
}

void	translate(int key, t_main *main)
{
	if (key == KEY_UP)
		main->cam->x_trans -= 10;
	if (key == KEY_DOWN)
		main->cam->x_trans += 10;
	if (key == KEY_LEFT)
		main->cam->y_trans -= 10;
	if (key == KEY_RIGHT)
		main->cam->y_trans += 10;
	draw(main->map, main->cam, main->mlx_inst, main->image);
}

void	change_projection(int key, t_main *main)
{
	if (key == KEY_C)
	{
		if (main->cam->projection == 1)
			main->cam->projection = 0;
		else
			main->cam->projection = 1;
	}
	reset_camera(15, main);
}
