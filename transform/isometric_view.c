/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_view.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 05:57:22 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/12 22:04:04 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_view(t_screen *screen)
{
	map_iterator(screen->map_view, &scale, &screen->map_info.scale);
	map_iterator(screen->map_view, &rotate, NULL);
	map_iterator(screen->map_view, &smash, NULL);
	map_iterator(screen->map_view, &up_z, NULL);
}
