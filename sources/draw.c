/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:14:00 by mbishop-          #+#    #+#             */
/*   Updated: 2022/06/27 14:14:04 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	background(t_image *image)
{
	int	*new_image;
	int	index;

	ft_bzero(image->address, WIN_WIDTH * WIN_HEIGHT * (image->bpp / 8));
	new_image = (int *)(image->address);
	index = 0;
	while (index < (WIN_WIDTH * WIN_HEIGHT))
	{
		new_image[index] = VP_BG1;
		index++;
	}
}

void	draw(t_map *map, t_cam *cam, t_mlx_inst *mlx_i, t_image *image)
{
	int	x;
	int	y;

	background(image);
	select_color(map);
	x = 0;
	while (x < map->rows)
	{
		y = 0;
		while (y < map->columns)
		{
			if (y + 1 < map->columns)
				draw_lines(projection(map->point[x][y], map, cam),
					projection(map->point[x][y + 1], map, cam), image);
			if (x + 1 < map->rows)
				draw_lines(projection(map->point[x][y], map, cam),
					projection(map->point[x + 1][y], map, cam), image);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx_i->mlx, mlx_i->mlx_win, image->image, 0, 0);
	print_menu(mlx_i);
}
