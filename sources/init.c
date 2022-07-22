/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:14:15 by mbishop-          #+#    #+#             */
/*   Updated: 2022/06/27 14:14:18 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_cam	*init_cam(t_map *map)
{
	t_cam		*cam;
	int			cam_width;
	int			cam_height;

	cam = (t_cam *)malloc(sizeof(t_cam));
	if (!cam)
		err_init();
	cam_width = (WIN_WIDTH / map->columns) / 2;
	cam_height = (WIN_HEIGHT / map->rows) / 2;
	if (cam_width < cam_height)
		cam->zoom = cam_width;
	else
		cam->zoom = cam_height;
	if (cam->zoom < 1)
		cam->zoom = 1;
	cam->x_rot = 0;
	cam->y_rot = 0;
	cam->z_rot = 0;
	cam->x_trans = 0;
	cam->y_trans = 0;
	cam->z_divisor = 2;
	cam->projection = 1;
	return (cam);
}

t_image	*init_image(t_mlx_inst *mlx, int width, int height)
{
	t_image	*new_image;

	new_image = (t_image *)malloc(sizeof (t_image));
	if (!new_image)
		err_init();
	new_image->width = width;
	new_image->height = height;
	new_image->image = mlx_new_image(mlx->mlx, width, height);
	new_image->address = mlx_get_data_addr(new_image->image, &new_image->bpp,
			&new_image->l_size, &new_image->endian);
	return (new_image);
}

t_map	*init_map(void)
{
	t_map		*init_map;

	init_map = (t_map *)malloc(sizeof(t_map));
	if (!init_map)
		err_init();
	init_map->columns = 0;
	init_map->rows = 0;
	init_map->max_z = MIN;
	init_map->min_z = MAX;
	init_map->point = NULL;
	return (init_map);
}

t_main	*init_main(void)
{
	t_main		*main;

	main = (t_main *)malloc(sizeof(t_main));
	if (!main)
		err_init();
	main->mlx_inst = init_mlx();
	if (!main->mlx_inst)
		err_init();
	return (main);
}
