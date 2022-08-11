/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_view.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 05:57:22 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/11 12:51:28 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_view(t_screen *screen)
{
	int	nb1;
	int	nbr;

	nbr = 0;
	nb1 = -90;
	map_iterator(screen->map_view, &scale, &screen->map_info.scale);
	map_iterator(screen->map_view, &rotate, &nb1);
	map_iterator(screen->map_view, &smash, &nbr);
	map_iterator(screen->map_view, &up_z, &nbr);
}
