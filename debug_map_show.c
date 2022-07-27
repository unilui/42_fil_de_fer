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
			if (selector == 'column')
				printf("%3d", line[column].column);
			if (selector == 'y')
				printf("%3d", line[column].y);
			if (selector == 'z')
				printf("%3d", line[column].z);
			if (line[column].eol)
				break;
			column++;
		}
		printf("\n");
		map++;
	}
}

void	render_map(t_img *img, t_pixel **map)
{
	int	line;
	int	column;

	line = 0;
	column = 0;
	while(map[line])
	{
		column = 0;
		while(map[line] + column)
		{
			if (!(map[line] + column)->eol)
				bresenham_line(img, map[line][column], map[line][column + 1]);
			if (map[line + 1])
				bresenham_line(img, map[line][column], map[line + 1][column]);
			if ((map[line] + column)->eol)
				break ;
			column++;
		}
		line++;
	}
}
