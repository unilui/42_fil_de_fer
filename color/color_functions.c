/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:53:24 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/11 12:52:40 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	rgb_encode(short int red, short int green, short int blue)
{
	t_rgb	color;

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

int	ft_hexatoi(const char *nptr)
{
	int	num;

	num = 0;
	while (*nptr == '0' || *nptr == 'x')
		nptr++;
	while ((*nptr >= '0' && *nptr <= '9')
		|| (*nptr >= 'a' && *nptr <= 'f')
		|| (*nptr >= 'A' && *nptr <= 'F'))
	{
		num = num * 16;
		if (*nptr >= '0' && *nptr <= '9')
			num += *nptr - '0';
		if (*nptr >= 'a' && *nptr <= 'f')
			num += *nptr - 87;
		if (*nptr >= 'A' && *nptr <= 'F')
			num += *nptr - 55;
		nptr++;
	}
	return (num);
}
