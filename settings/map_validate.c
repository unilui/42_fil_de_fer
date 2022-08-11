/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 23:47:17 by lufelip2          #+#    #+#             */
/*   Updated: 2022/08/11 12:50:25 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

char	*map_validate(char *file_path)
{
	int	rows;
	int	columns;

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
