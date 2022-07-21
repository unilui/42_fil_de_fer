/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:39:57 by lufelip2          #+#    #+#             */
/*   Updated: 2022/07/21 02:32:51 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
    char    **pixel_map;

	if (argc == 2)
        pixel_map = load_map(argv[1]);
        // if pixel_map 
        //     render
    else
        return (2);
        
    return (0);
}
