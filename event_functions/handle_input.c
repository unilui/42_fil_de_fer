/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 07:44:03 by lufelip2          #+#    #+#             */
/*   Updated: 2022/07/23 07:51:11 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	handle_input(int keysym, t_screen *screen)
{
	if (keysym == 53)
	{
		mlx_destroy_window(screen->mlx, screen->window);
		exit(0);
	}
	return (0);
}
