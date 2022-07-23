/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 07:15:52 by lufelip2          #+#    #+#             */
/*   Updated: 2022/07/23 07:16:51 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*addr;
	int		*pixel;

	addr = img->addr + (y * img->line_len + x * (img->bpp / 8));
	pixel = (int *)addr;
	*pixel = color;
}
