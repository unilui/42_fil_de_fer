/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 07:46:52 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/11 12:01:42 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	exit_fdf(t_screen *screen)
{
	free_map(screen->map);
	free_map(screen->map_view);
	mlx_destroy_image(screen->mlx, screen->img.mlx_img);
	mlx_destroy_window(screen->mlx, screen->window);
	mlx_destroy_display(screen->mlx);
	free(screen->mlx);
	exit(0);
}
