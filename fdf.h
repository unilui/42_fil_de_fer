/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:48:30 by lufelip2          #+#    #+#             */
/*   Updated: 2022/07/23 07:47:17 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include <stdlib.h>
#include <fcntl.h>
#include <mlx.h>
#include <stdio.h> // REMOVER!!

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

typedef union u_color
{
	int	color;
	char rgb[4];
}	t_rgb;

typedef struct s_pixel
{
	int	x;
	int y;
	int z;
	int color;
	short int	eol;
}	t_pixel;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_screen
{
	void	*mlx;
	void	*window;
	t_img	img;
	t_pixel	**map;
}	t_screen;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

int		rgb_encode(short int red, short int green, short int blue);
t_pixel	**load_map(char *file_path);
void	free_table(char **table);
void	free_map(t_pixel **table);
t_screen	load_mlx(void);
void	load_hooks(t_screen *screen);
void	render_grid(t_screen *screen);
void	img_pixel_put(t_img *img, int x, int y, int color);
int		render_rect(t_img *img, t_rect rect);
int		render_background(t_img *img, int color);
int		render(t_screen *screen);
int		handle_input(int keysym, t_screen *screen);
int		sair(t_screen *screen);

#endif