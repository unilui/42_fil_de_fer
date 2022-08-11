/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 05:42:04 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/11 11:49:00 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_mouse(int button, int x, int y, t_screen *screen)
{
	if (button == 5)
	{
		screen->map_info.scale += 1;
	}
	if (button == 4)
	{
		if (screen->map_info.scale - 1 > 0)
			screen->map_info.scale -= 1;
	}
	(void)x;
	(void)y;
	(void)screen;
	return (0);
}

void	load_hooks(t_screen *screen)
{
	mlx_loop_hook(screen->mlx, &render, screen);
	mlx_key_hook(screen->window, &handle_input, screen);
	mlx_mouse_hook(screen->window, &handle_mouse, screen);
	mlx_hook(screen->window, 17, 0, &exit_fdf, screen);
}
