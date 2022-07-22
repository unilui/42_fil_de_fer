/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:36:13 by lufelip2          #+#    #+#             */
/*   Updated: 2022/07/22 06:12:11 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "utils/get_next_line.h"

static int		all_lines(char *file_path);
static int		line_len(char *file_path);
static t_pixel	*split_line(int fd, int line_len, int y);
static t_pixel	pixel_format(char *data, int x, int y);

t_pixel **load_map(char *file_path)
{
	t_pixel **map;
	int		lines;
	int		len;
	int		fd;
	int		y;

	y = 0;
	lines = 0;
	map = NULL;
	fd = open(file_path, O_RDONLY);
	if (fd != -1)
		lines = all_lines(file_path);
		len = line_len(file_path);
	if (lines)
	{
		map = malloc((lines + 1) * sizeof(t_pixel *));
		if (!map)
			return (NULL);
		while (y < lines)
			map[y++] = split_line(fd, len, y);
		map[y] = NULL;
		close(fd);
	}
	return (map);
}

static t_pixel	*split_line(int fd, int len, int y)
{
	t_pixel	*line;
	char	*file_line;
	char	**splitted_line;
	int		x;

	x = 0;
	line = malloc((len) * sizeof(t_pixel));
	if (!line)
		return (NULL);
	file_line = get_next_line(fd);
	splitted_line = ft_split(file_line, ' ');
	while (x < len)
		line[x++] = pixel_format(splitted_line[x], x, y);
	line[x - 1].eol = 1;
	free(file_line);
	free_table(splitted_line);
	return (line);
}

static t_pixel	pixel_format(char *data, int x, int y)
{
	t_pixel	pixel;

	pixel.x = --x;
	pixel.y = --y;
	pixel.z = ft_atoi(data);
	if (ft_strrchr(data, ','))
		pixel.color = rgb_encode(255, 255, 255); // Mudar pra função que converte hexa
	else
		pixel.color = rgb_encode(255, 255, 255);
	return (pixel);
}

static int	line_len(char *file_path)
{
	int		fd;
	int		len;
	char	*line;
	char	**splitted_line;

	len = 0;
	fd = open(file_path, O_RDONLY);
	line = get_next_line(fd);
	splitted_line = ft_split(line, ' ');
	while(splitted_line[len])
		len++;
	get_next_line(-(fd));
	close(fd);
	free(line);
	free_table(splitted_line);
	return (len);
}

static int	all_lines(char *file_path)
{
	int		fd;
	int		lines;
	char	*tmp;

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
