/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 03:21:08 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/03 01:36:43 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_table(char **table)
{
	char	**tmp;

	tmp = table;
	while (*table)
		free(*table++);
	free(tmp);
}

void	free_map(t_pixel **table)
{
	t_pixel	**tmp;

	tmp = table;
	while (*table)
		free(*table++);
	free(tmp);
}
