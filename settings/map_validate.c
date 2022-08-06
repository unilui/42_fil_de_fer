/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 23:47:17 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/06 02:19:42 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static int	line_len(char *file_path);
static int	all_lines(char *file_path);

char	*map_validate(char *file_path)
{
	int rows;
	int columns;

	rows = all_lines(file_path);
	columns = line_len(file_path);
	if (rows && columns)
	{
		if (ft_strrchr(file_path, '/'))
			return (ft_strrchr(file_path, '/') + 1);
		else
			return (file_path);
	}
	return (NULL);
}

static int	line_len(char *file_path)
{
	int		fd;
	int		len;
	char	*line;
	char	**splitted_line;

	len = 0;
	fd = open(file_path, O_RDONLY);
	if (fd != -1)
	{
		line = get_next_line(fd);
		splitted_line = ft_split(line, ' ');
		while (splitted_line[len])
			len++;
		get_next_line(-(fd));
		close(fd);
		free(line);
		free_table(splitted_line);
		return (len);
	}
	return (len);
}

static int	all_lines(char *file_path)
{
	int		fd;
	int		lines;
	char	*tmp;

	lines = 0;
	fd = open(file_path, O_RDONLY);
	if (fd != -1)
	{
		tmp = get_next_line(fd);
		while (tmp)
		{
			free(tmp);
			tmp = get_next_line(fd);
			lines++;
		}
		close(fd);
		return (lines);
	}
	return (lines);
}
