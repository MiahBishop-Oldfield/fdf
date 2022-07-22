/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:14:48 by mbishop-          #+#    #+#             */
/*   Updated: 2022/07/08 10:58:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	int				fd;
	t_main			*main;

	if (argc != 2)
		err_bad_args();
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		err_bad_file();
	main = init_main();
	main->map = init_map();
	if (read_map(fd, main->map) != 1)
		err_bad_file();
	main->image = init_image(main->mlx_inst, WIN_WIDTH, WIN_HEIGHT);
	main->cam = init_cam(main->map);
	draw(main->map, main->cam, main->mlx_inst, main->image);
	set_mlx_hooks(main);
	mlx_loop(main->mlx_inst->mlx);
	return (0);
}
