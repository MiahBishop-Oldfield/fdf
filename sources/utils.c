/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:15:57 by mbishop-          #+#    #+#             */
/*   Updated: 2022/06/27 14:15:58 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	get_percent(int start, int end, int current)
{
	double		place;
	double		distance;

	place = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return ((place / distance));
}

int	get_light(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

void	set_max_height(t_map_point row, t_map *map)
{
	if (row.z > map->max_z)
		map->max_z = row.z;
	if (row.z < map->min_z)
		map->min_z = row.z;
	return ;
}

t_map_point	set_point(int col, int row, char *data)
{
	t_map_point		ret;

	ret.y = col;
	ret.x = row;
	if (data)
		ret.z = ft_atoi(data);
	else
		ret.z = 0;
	ret.color = read_color(ft_strchr(data, ','));
	return (ret);
}

void	free_array(char **arr)
{
	int		index;

	index = 0;
	while (arr[index])
		free(arr[index++]);
	free(arr);
}
