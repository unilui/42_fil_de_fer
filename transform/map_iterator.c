/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 05:14:18 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/03 01:38:48 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_iterator(t_pixel **map, void (*funct)(t_pixel*, void*), void *args)
{
	t_pixel	*line;
	int		column;

	while (*map)
	{
		line = *map;
		column = 0;
		while (line)
		{
			funct((line + column), args);
			if (line[column].eol)
				break;
			column++;
		}
		map++;
	}
}
