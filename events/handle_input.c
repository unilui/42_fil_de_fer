/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 07:44:03 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/11 11:55:30 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_input(int keysym, t_screen *screen)
{
	if (keysym == XK_Escape)
		exit_fdf(screen);
	else if (keysym == XK_Up)
		map_iterator(screen->map, &move, &"d");
	else if (keysym == XK_Down)
		map_iterator(screen->map, &move, &"u");
	else if (keysym == XK_Left)
		map_iterator(screen->map, &move, &"r");
	else if (keysym == XK_Right)
		map_iterator(screen->map, &move, &"l");
	return (0);
}
