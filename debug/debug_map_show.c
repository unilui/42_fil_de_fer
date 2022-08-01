/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_map_show.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 06:00:19 by lufelip2          #+#    #+#             */
/*   Updated: 2022/07/28 06:00:36 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	map_show(t_pixel **map, char selector)
{
	t_pixel	*line;
	int		column;

	while (*map)
	{
		line = *map;
		column = 0;
		while (line)
		{
			if (selector == 'x')
				printf("%3d", line[column].x);
			if (selector == 'y')
				printf("%3d", line[column].y);
			if (selector == 'z')
				printf("%3d", line[column].z);
			if (line[column].eol)
				break ;
			column++;
		}
		printf("\n");
		map++;
	}
}
