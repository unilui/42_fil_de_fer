/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 05:28:30 by lufelip2          #+#    #+#             */
/*   Updated: 2022/07/28 05:29:25 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	scale(t_pixel *pixel, void *args)
{
	int	*scale;

	scale = (int *)args;
	pixel->x *= *scale;
	pixel->y *= *scale;
}

void	rotate(t_pixel *pixel, void *args)
{
	int	*scale;
	int	x;
	int	y;

	scale = (int *)args;
	x = (-(pixel->x * -1) + (pixel->y * 1));
	y = (-(pixel->x * 1) + (pixel->y * 1));
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
}
