/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 07:19:04 by lufelip2          #+#    #+#             */
/*   Updated: 2022/07/23 07:19:21 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int render_rect(t_img *img, t_rect rect)
{
	int	x;
	int	y;

	y = rect.y;
	while (y < (rect.y + rect.height))
	{
		x = rect.x;
		while (x < (rect.x + rect.width))
			img_pixel_put(img, x++, y, rect.color);
		y++;
	}
	return (0);
}
