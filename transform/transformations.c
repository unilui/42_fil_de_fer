/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 05:28:30 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/11 12:51:10 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale(t_pixel *pixel, void *args)
{
	int	*scale;

	scale = (int *)args;
	pixel->x *= *scale;
	pixel->y *= *scale;
	pixel->z *= *scale;
}

void	rotate(t_pixel *pixel, void *args)
{
	int	*scale;
	int	x;
	int	y;

	scale = (int *)args;
	x = ((pixel->x * 1) + (pixel->y * -1));
	y = ((pixel->x * 1) + (pixel->y * 1));
	pixel->x = x;
	pixel->y = y;
}

void	smash(t_pixel *pixel, void *args)
{
	int	*scale;

	scale = (int *)args;
	pixel->y /= 2;
}

void	up_z(t_pixel *pixel, void *args)
{
	int	*scale;

	scale = (int *)args;
	if (pixel->z > 0)
		pixel->y += pixel->z;
	else
		pixel->y -= pixel->z;
}

void	move(t_pixel *pixel, void *args)
{
	char	*direction;

	direction = (char *)args;
	if (*direction == 'u')
	{
		pixel->y += 1;
		pixel->x += 1;
	}
	else if (*direction == 'd')
	{
		pixel->y += -1;
		pixel->x += -1;
	}
	else if (*direction == 'l')
	{
		pixel->y += 1;
		pixel->x += -1;
	}
	else
	{
		pixel->x += 1;
		pixel->y += -1;
	}
}
