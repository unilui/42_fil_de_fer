/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 05:26:36 by lufelip2          #+#    #+#             */
/*   Updated: 2022/07/27 01:52:49 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_screen	load_mlx(void)
{
	t_screen	screen;
	
	screen.width = 1280; // Pegar do arquivo config
	screen.height = 720;

	screen.mlx = mlx_init();
	screen.window = mlx_new_window(
		screen.mlx,
		screen.width,
		screen.height,
		"Hello, screen!"); // Nome do arquivo carregado
	screen.img.mlx_img = mlx_new_image(
		screen.mlx,
		screen.width, 
		screen.height);
	screen.img.addr = mlx_get_data_addr(
		screen.img.mlx_img,
		&screen.img.bpp,
		&screen.img.line_len,
		&screen.img.endian);
	screen.img.limits.top = (screen.height / 2);
	screen.img.limits.bottom = -(screen.height / 2);
	screen.img.limits.left = -(screen.width / 2);
	screen.img.limits.right = (screen.width / 2);
	return (screen);
}
