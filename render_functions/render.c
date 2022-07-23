/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 07:27:39 by lufelip2          #+#    #+#             */
/*   Updated: 2022/07/23 07:28:27 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	render(t_screen *screen)
{
	render_background(&screen->img, rgb_encode(255, 255, 255));
	render_rect(&screen->img, (t_rect){
		(WINDOW_WIDTH / 2 - 50), (WINDOW_HEIGHT / 2 - 50),
		100, 100, rgb_encode(0, 255, 0)
	});
	mlx_put_image_to_window(screen->mlx, screen->window, screen->img.mlx_img, 0, 0);
	return (0);
}