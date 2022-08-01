/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 05:57:22 by lufelip2          #+#    #+#             */
/*   Updated: 2022/07/31 17:22:05 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	isometric_view(t_screen *screen)
{
	int	nbr;
	int	nb1;

	nbr = 40;
	nb1 = -90;
	center_origin(screen->map);
	map_iterator(screen->map, &scale, &nbr);
	map_iterator(screen->map, &rotate, &nb1);
	map_iterator(screen->map, &smash, &nbr);
	map_iterator(screen->map, &up_z, &nbr);
}
