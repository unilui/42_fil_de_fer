/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:39:57 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/11 13:05:07 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_screen	screen;
	char		*file_name;

	if (argc == 2)
	{
		file_name = map_validate(argv[1]);
		if (file_name)
		{
			screen = load_mlx(1280, 720, file_name);
			load_map(&screen, argv[1]);
			load_hooks(&screen);
			mlx_loop(screen.mlx);
		}
		else
			return (message(FILE_ERROR));
	}
	else
		return (message(MISSING_FILE));
	return (0);
}
