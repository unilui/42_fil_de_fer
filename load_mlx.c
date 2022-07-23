/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 05:26:36 by lufelip2          #+#    #+#             */
/*   Updated: 2022/07/23 07:09:00 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_screen	load_mlx(void)
{
	t_screen	screen;
	
	screen.mlx = mlx_init();
	screen.window = mlx_new_window(
		screen.mlx,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		"Hello, screen!"); // Nome do arquivo carregado
	screen.img.mlx_img = mlx_new_image(
		screen.mlx,
		WINDOW_WIDTH, WINDOW_HEIGHT);
	screen.img.addr = mlx_get_data_addr(
		screen.img.mlx_img,
		&screen.img.bpp,
		&screen.img.line_len,
		&screen.img.endian);
	return (screen);
}
