/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:18:49 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/11 10:46:42 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel	**create_map(int rows, int columns)
{
	t_pixel	**new_map;
	int		i;

	i = 0;
	new_map = malloc((rows + 1) * sizeof(t_pixel *));
	if (!new_map)
		return (NULL);
	while (i < rows)
		new_map[i++] = malloc((columns) * sizeof(t_pixel));
	new_map[i] = NULL;
	return (new_map);
}

void	map_copy(t_pixel **src, t_pixel **dest)
{
	t_pixel	*src_line;
	t_pixel	*dest_line;
	int		column;

	while (*src)
	{
		src_line = *src;
		dest_line = *dest;
		column = 0;
		while (src_line)
		{
			dest_line[column].x = src_line[column].x;
			dest_line[column].y = src_line[column].y;
			dest_line[column].z = src_line[column].z;
			dest_line[column].eol = src_line[column].eol;
			dest_line[column].color = src_line[column].color;
			if (src_line[column].eol)
				break ;
			column++;
		}
		dest++;
		src++;
	}
}
