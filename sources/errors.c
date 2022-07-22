/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbishop- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:13:49 by mbishop-          #+#    #+#             */
/*   Updated: 2022/06/27 14:13:51 by mbishop-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	err_bad_args(void)
{
	ft_putstr_fd("Error : incorrect usage", 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Usage - ./fdf <path/file.fdf>", 1);
	ft_putchar_fd('\n', 1);
	exit(1);
}

void	err_bad_file(void)
{
	ft_putstr_fd("Error : unable to open file or bad file", 1);
	ft_putchar_fd('\n', 1);
	exit(1);
}

void	err_init(void)
{
	ft_putstr_fd("Error : Failed to initialize", 1);
	ft_putchar_fd('\n', 1);
	exit(1);
}
