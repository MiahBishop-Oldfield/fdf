/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:15:11 by mbishop-          #+#    #+#             */
/*   Updated: 2022/06/27 14:15:13 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_mlx_hooks(t_main *main)
{
	mlx_hook(main->mlx_inst->mlx_win, 2, 0, key_input, main);
	mlx_hook(main->mlx_inst->mlx_win, 17, 0, close_window, main);
	return ;
}

t_mlx_inst	*init_mlx(void)
{
	t_mlx_inst		*mlx_inst;

	mlx_inst = (t_mlx_inst *)malloc(sizeof(t_mlx_inst));
	if (!mlx_inst)
		err_init();
	mlx_inst->mlx = mlx_init();
	mlx_inst->mlx_win = mlx_new_window(mlx_inst->mlx, WIN_WIDTH,
			WIN_HEIGHT, WIN_TITLE);
	return (mlx_inst);
}
