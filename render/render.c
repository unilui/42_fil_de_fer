/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 07:27:39 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/11 12:54:18 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	render(t_screen *screen)
{
	background(&screen->img, rgb_encode(0, 0, 0));
	draw_map(screen);
	mlx_put_image_to_window(
		screen->mlx,
		screen->window,
		screen->img.mlx_img, 0, 0);
	map_copy(screen->map, screen->map_view);
	return (0);
}
