/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 05:42:04 by lufelip2          #+#    #+#             */
/*   Updated: 2022/07/23 07:47:33 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	load_hooks(t_screen *screen)
{
	mlx_loop_hook(screen->mlx, &render, screen);
	mlx_key_hook(screen->window, &handle_input, screen);
	mlx_hook(screen->window, 17, 0, &sair, screen);
}
