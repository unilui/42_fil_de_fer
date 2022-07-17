/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:53:24 by lufelip2          #+#    #+#             */
/*   Updated: 2022/07/16 19:03:12 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	rgb_encode(short int red, short int green, short int blue)
{
	t_rgb color;

	if (red < 0 || red > 255)
		red = 255;
	if (green < 0 || green > 255)
		green = 255;
	if (blue < 0 || blue > 255)
		blue = 255;	
	color.rgb[3] = 0;
	color.rgb[2] = red;
	color.rgb[1] = green;
	color.rgb[0] = blue;
	return (color.color);
}
