/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 07:20:13 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/03 01:37:35 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	background(t_img *img, int color)
{
	int	x;
	int	y;

	y = img->limits.top;
	while (y >= img->limits.bottom)
	{
		x = img->limits.left;
		while (x <= img->limits.right)
			pixel_put(img, x++, y, color);
		y--;
	}
	return (0);
}
