/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:48:30 by lufelip2          #+#    #+#             */
/*   Updated: 2022/07/17 01:32:50 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

// cc test.c -lX11 -lXext -lmlx -> linux
// cc test.c -lmlx -framework OpenGL -framework AppKit

#include <stdlib.h>
#include <mlx.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

typedef union u_color
{
	int	color;
	char rgb[4];
}	t_rgb;

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
}	t_screen;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

int	rgb_encode(short int red, short int green, short int blue);

#endif