/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:14:49 by mbishop-          #+#    #+#             */
/*   Updated: 2022/07/08 10:59:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../minilibx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define WIN_WIDTH 		1280
# define WIN_HEIGHT 	800
# define WIN_TITLE 		"fdf"

# define MAX 			2147483647
# define MIN 			-2147483648

# define KEY_A 			0
# define KEY_S 			1
# define KEY_D 			2
# define KEY_F			3
# define KEY_Z 			6
# define KEY_X 			7
# define KEY_C 			8
# define KEY_V			9
# define KEY_Q 			12
# define KEY_W 			13
# define KEY_E 			14
# define KEY_R			15
# define KEY_ESC 		53
# define KEY_LEFT 		123
# define KEY_RIGHT 		124
# define KEY_DOWN 		125
# define KEY_UP 		126

//Menu text
# define TEXT_A			0xFFFFFF
# define TEXT_B			0xFFFFFF

//Colors
# define MONO_25		0x00FFEF
# define MONO_50 		0x00FFEF
# define MONO_75 		0xBFBFBF
# define MONO_100 		0xFFFFFF
# define MONO_BG 		0x000000

# define VP_25			0x110068
# define VP_50	 		0x006EFF
# define VP_75	 		0x1AC5FF
# define VP_100 		0x3DF7FF
# define VP_BG1 		0x000000
# define VP_BG2			0x000000

typedef struct s_map_point
{
	int					x;
	int					y;
	int					z;
	int					color;
}	t_map_point;

typedef struct s_map
{
	int					rows;
	int					columns;
	int					max_z;
	int					min_z;
	t_map_point			**point;
}	t_map;

typedef struct s_image
{
	void				*image;
	char				*address;
	int					width;
	int					height;
	int					bpp;
	int					l_size;
	int					endian;
}	t_image;

typedef struct s_cam
{
	int					x_trans;
	int					y_trans;
	double				x_rot;
	double				y_rot;
	double				z_rot;
	float				z_divisor;
	int					zoom;
	int					projection;
}	t_cam;

typedef struct s_mlx_inst
{
	void				*mlx;
	void				*mlx_win;
}	t_mlx_inst;

typedef struct s_main
{
	t_mlx_inst			*mlx_inst;
	t_image				*image;
	t_cam				*cam;
	t_map				*map;
}	t_main;

void				reset_camera(int key, t_main *main);
int					close_window(t_main *main);
void				zoom(int key, t_main *main);
void				rotate(int key, t_main *main);
void				change_height(int key, t_main *main);
void				translate(int key, t_main *main);
void				change_projection(int key, t_main *main);
void				draw(t_map *map, t_cam *cam, t_mlx_inst *mlx_i,
						t_image *image);
void				err_bad_args(void);
void				err_bad_file(void);
void				err_init(void);
t_cam				*init_cam(t_map *map);
t_image				*init_image(t_mlx_inst *mlx, int width, int height);
t_map				*init_map(void);
t_main				*init_main(void);
void				draw_lines(t_map_point start, t_map_point end,
						t_image *image);
int					main(int argc, char **argv);
void				print_menu(t_mlx_inst *mlx_inst);
void				set_mlx_hooks(t_main *main);
t_mlx_inst			*init_mlx(void);
t_map_point			projection(t_map_point point, t_map *map, t_cam *cam);
int					read_color(char *data);
void				select_color(t_map *map);
double				get_percent(int start, int end, int current);
int					get_light(int start, int end, double percent);
int					get_color(t_map_point cur, t_map_point start,
						t_map_point end, t_map_point delta);
double				get_percent(int start, int end, int current);
int					get_light(int start, int end, double percent);
void				set_max_height(t_map_point row, t_map *map);
t_map_point			set_point(int col, int row, char *data);
void				free_array(char **arr);
int					read_map(int fd, t_map *map);
int					key_input(int key, void *param);

#endif