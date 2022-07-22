/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:14:58 by mbishop-          #+#    #+#             */
/*   Updated: 2022/06/27 14:15:00 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_menu(t_mlx_inst *mlx_inst)
{
	int		y;
	void	*mlx;
	void	*mlx_win;

	y = 0;
	mlx = mlx_inst->mlx;
	mlx_win = mlx_inst->mlx_win;
	mlx_string_put(mlx, mlx_win, 10, y += 20, TEXT_A, "Controls");
	mlx_string_put(mlx, mlx_win, 10, y += 40, TEXT_A, "Move");
	mlx_string_put(mlx, mlx_win, 50, y += 20, TEXT_B, "Arrow Keys");
	mlx_string_put(mlx, mlx_win, 10, y += 40, TEXT_A, "Rotate X");
	mlx_string_put(mlx, mlx_win, 50, y += 20, TEXT_B, "Q / W");
	mlx_string_put(mlx, mlx_win, 10, y += 40, TEXT_A, "Rotate Y");
	mlx_string_put(mlx, mlx_win, 50, y += 20, TEXT_B, "A / S");
	mlx_string_put(mlx, mlx_win, 10, y += 40, TEXT_A, "Rotate Z");
	mlx_string_put(mlx, mlx_win, 50, y += 20, TEXT_B, "Z / X");
	mlx_string_put(mlx, mlx_win, 10, y += 40, TEXT_A, "Zoom");
	mlx_string_put(mlx, mlx_win, 50, y += 20, TEXT_B, "E / D");
	mlx_string_put(mlx, mlx_win, 10, y += 40, TEXT_A, "Adjust Height");
	mlx_string_put(mlx, mlx_win, 50, y += 20, TEXT_B, "F / V");
	mlx_string_put(mlx, mlx_win, 10, y += 40, TEXT_A, "Change Projection");
	mlx_string_put(mlx, mlx_win, 50, y += 20, TEXT_B, "C");
	mlx_string_put(mlx, mlx_win, 10, y += 40, TEXT_A, "Reset Camera");
	mlx_string_put(mlx, mlx_win, 50, y += 20, TEXT_B, "R");
}
