/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:39:57 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/05 02:27:05 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_screen	screen;

	if (argc == 2)
	{
		screen = load_mlx();
		screen.map = load_map(argv[1]);
		map_get_data(&screen);
		load_hooks(&screen);
		isometric_view(&screen);
		mlx_loop(screen.mlx);
	}
	else
		return (2);
	return (0);
}
