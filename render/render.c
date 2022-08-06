/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 07:27:39 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/05 23:12:39 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	render(t_screen *screen)
{
	draw_map(&screen->img, screen->map);
	mlx_put_image_to_window(
		screen->mlx,
		screen->window,
		screen->img.mlx_img, 0, 0);
	return (0);
}
