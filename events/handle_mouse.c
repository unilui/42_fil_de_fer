/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 22:07:23 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/12 22:08:12 by lufelip2         ###   ########.fr       */
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
