/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:48:30 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/11 13:04:32 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>

# define MISSING_FILE "Usage : ./fdf <filename>\n"
# define FILE_ERROR "\
There is something wrong with your file. Is the name correct?\n"

typedef union u_color
{
	int		color;
	char	rgb[4];
}	t_rgb;

typedef struct s_pixel
{
	int			x;
	int			y;
	int			z;
	int			color;
	short int	eol;
}	t_pixel;

typedef struct s_limits
{
	int	top;
	int	bottom;
	int	left;
	int	right;
}	t_limits;

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	t_limits	limits;
}	t_img;

typedef struct s_map_info
{
	int	columns;
	int	rows;
	int	scale;
}	t_map_info;

typedef struct s_screen
{
	void		*mlx;
	void		*window;
	t_img		img;
	t_pixel		**map;
	t_pixel		**map_view;
	t_map_info	map_info;
	int			width;
	int			height;
}	t_screen;

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	adx;
	int	ady;
	int	sx;
	int	sy;
	int	eps;
}	t_bsh;

int			rgb_encode(short int red, short int green, short int blue);
void		load_map(t_screen *screen, char *file_path);
t_pixel		**read_map(char *file_path);
void		free_table(char **table);
void		free_map(t_pixel **table);
t_screen	load_mlx(int width, int height, char *file_name);
void		load_hooks(t_screen *screen);
void		isometric_view(t_screen *screen);
void		pixel_put(t_img *img, int x, int y, int color);
int			background(t_img *img, int color);
int			render(t_screen *screen);
int			handle_input(int keysym, t_screen *screen);
int			exit_fdf(t_screen *screen);
void		bresenham_line(t_img *img, t_pixel start, t_pixel end);
void		map_iterator(t_pixel **map,
				void (*funct)(t_pixel*, void*),
				void *args);
void		scale(t_pixel *pixel, void *args);
void		rotate(t_pixel *pixel, void *args);
void		smash(t_pixel *pixel, void *args);
void		up_z(t_pixel *pixel, void *args);
void		draw_map(t_screen *screen);
void		center_origin(t_pixel **map, int x_start, int y_start);
int			map_count_columns(t_pixel **map);
int			map_count_rows(t_pixel **map);
void		map_get_data(t_screen *screen);
int			ft_hexatoi(const char *nptr);
char		*map_validate(char *file_path);
int			line_len(char *file_path);
int			all_lines(char *file_path);
int			background(t_img *img, int color);
t_pixel		**create_map(int rows, int columns);
void		map_copy(t_pixel **src, t_pixel **dest);
void		move(t_pixel *pixel, void *args);
int			message(char *str);

#endif
