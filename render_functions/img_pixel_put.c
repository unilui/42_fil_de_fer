/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 07:15:52 by lufelip2          #+#    #+#             */
/*   Updated: 2022/07/27 02:03:39 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*addr;
	int		*pixel;
	int		y_map;
	int		x_map;

	if (x < img->limits.left || x > img->limits.right)
		return ;
	if (y > img->limits.top || y < img->limits.bottom)
		return ;
	y_map = (img->limits.top + y) * img->line_len;
	x_map = (img->limits.right + x) * (img->bpp / 8);
	addr = img->addr + y_map + x_map;
	pixel = (int *)addr;
	*pixel = color;
}
