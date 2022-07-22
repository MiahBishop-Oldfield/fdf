/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:15:24 by mbishop-          #+#    #+#             */
/*   Updated: 2022/06/27 14:15:26 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	isometric(int *x, int *y, int z)
{
	int		prev_x;
	int		prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = -z + (prev_x - prev_y) * sin(0.523599);
	*y = (prev_x + prev_y) * cos(0.523599);
}

static void	rotate_x(int *y, int *z, double x_rot)
{
	int		prev_y;

	prev_y = *y;
	*y = prev_y * cos(x_rot) + *z * sin(x_rot);
	*z = -prev_y * sin(x_rot) + *z * cos(x_rot);
}

static void	rotate_y(int *x, int *z, double y_rot)
{
	int		prev_x;

	prev_x = *x;
	*x = prev_x * cos(y_rot) + *z * sin(y_rot);
	*z = -prev_x * sin(y_rot) + *z * cos(y_rot);
}

static void	rotate_z(int *x, int *y, double z_rot)
{
	int		prev_x;
	int		prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(z_rot) - prev_y * sin(z_rot);
	*y = prev_x * sin(z_rot) + prev_y * cos(z_rot);
}

t_map_point	projection(t_map_point point, t_map *map, t_cam *cam)
{
	point.x *= cam->zoom;
	point.y *= cam->zoom;
	point.z *= cam->zoom / cam->z_divisor;
	point.y -= (map->columns * cam->zoom) / 2;
	point.x -= (map->rows * cam->zoom) / 2;
	rotate_x(&point.y, &point.z, cam->x_rot);
	rotate_y(&point.x, &point.z, cam->y_rot);
	rotate_z(&point.x, &point.y, cam->z_rot);
	if (cam->projection == 1)
		isometric(&point.x, &point.y, point.z);
	point.x += (WIN_HEIGHT / 2) + cam->x_trans;
	point.y += (WIN_WIDTH / 2) + cam->y_trans;
	return (point);
}
