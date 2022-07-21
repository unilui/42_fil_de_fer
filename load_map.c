/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:36:13 by lufelip2          #+#    #+#             */
/*   Updated: 2022/07/21 05:38:35 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "utils/get_next_line.h"

static int  all_lines(char *file_path);

t_pixel **load_map(char *file_path)
{
	t_pixel **map;
	int     lines;
	int     fd;
	int     i;

	i = 0;
	lines = 0;
	map = NULL;
	fd = open(file_path, O_RDONLY);
	if (fd != -1)
		lines = all_lines(file_path);
	if (lines)
	{
		map = malloc((lines + 1) * sizeof(t_pixel *));
		if (!map)
			return (NULL);
		while (i < lines)
			map[i++] = parse_line(fd);
		map[lines] = NULL;
		close(fd);
	}
	return (map);
}

static int  all_lines(char *file_path)
{
	int     fd;
	int     lines;
	char    *tmp;

	lines = 0;
	fd = open(file_path, O_RDONLY);
	tmp = get_next_line(fd);
	while(tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		lines++;
	}
	close(fd);
	return (lines);
}
