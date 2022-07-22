/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:33:15 by mbishop-          #+#    #+#             */
/*   Updated: 2022/07/11 15:33:17 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	print_key(int key)
{
	ft_putstr_fd("Key Pressed - ", 1);
	ft_putnbr_fd(key, 1);
	ft_putchar_fd('\n', 1);
	return ;
}

int	key_input(int key, void *param)
{
	t_main		*main;

	main = (t_main *)param;
	print_key(key);
	if (key == KEY_ESC)
		close_window(main);
	else if (key == KEY_Q || key == KEY_W || key == KEY_A || key == KEY_S
		|| key == KEY_Z || key == KEY_X)
		rotate(key, main);
	else if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT
		|| key == KEY_RIGHT)
		translate(key, main);
	else if (key == KEY_E || key == KEY_D)
		zoom(key, main);
	else if (key == KEY_R)
		reset_camera(key, main);
	else if (key == KEY_C)
		change_projection(key, main);
	else if (key == KEY_F || key == KEY_V)
		change_height(key, main);
	return (0);
}
