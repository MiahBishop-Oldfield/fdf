/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:14:30 by mbishop-          #+#    #+#             */
/*   Updated: 2022/06/27 14:14:33 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	set_error(t_map_point delta)
{
	int		err;

	if (delta.x > delta.y)
		err = delta.x;
	else
		err = -delta.y;
	err /= 2;
	return (err);
}

static t_map_point	set_sign(t_map_point start, t_map_point end)
{
	t_map_point		sign;

	if (start.x < end.x)
		sign.x = 1;
	else
		sign.x = -1;
	if (start.y < end.y)
		sign.y = 1;
	else
		sign.y = -1;
	return (sign);
}

static int	absolute(int num)
{
	if (num < 0)
		num = num * -1;
	return (num);
}

static void	draw_pixel(t_image *image, int x, int y, int color)
{
	int		index;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		index = (x * image->bpp / 8) + (y * image->l_size);
		image->address[index] = color;
		image->address[++index] = color >> 8;
		image->address[++index] = color >> 16;
	}
}

void	draw_lines(t_map_point start, t_map_point end, t_image *image)
{
	t_map_point		delta;
	t_map_point		sign;
	t_map_point		cur;
	int				error[2];

	delta.x = absolute(end.x - start.x);
	delta.y = absolute(end.y - start.y);
	sign = set_sign(start, end);
	error[0] = set_error(delta);
	cur = start;
	while (cur.x != end.x || cur.y != end.y)
	{
		draw_pixel(image, cur.y, cur.x, get_color(cur, start, end, delta));
		error[1] = error[0];
		if (error[1] > -delta.x)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.y)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}
