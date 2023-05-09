/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:12:09 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/09 17:24:42 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "fdf.h"
#include "color_defs.h"
#include "mlx.h"

/* 		To center image: 
* 		(WINDOW_SIZE_X - IMAGE_SIZE_X) / 2 ... (WINDOW_SIZE_Y - IMAGE_SIZE_Y) / 2
* 		where IMAGE_SIZE is MAP_LIMITS_X * SCALE
*/
static void	center_image(t_map *map, t_vars *vars, t_data *data, int scale)
{
	int	s1;
	int	s2;

	s1 = (1920 - map->limits[X] * scale) / 2;
	s2 = (1080 - map->limits[Y] * scale) / 2;
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, s1, s2);
}

int	draw_screen(t_map *map, t_vars *vars, t_data *data)
{
	int	i;
	int	j;
	int	k;
	int	scale;

	i = 0;
	j = 0;
	scale = 80;
	k = map->limits[X];	
	while (i < (map->limits[X] * map->limits[Y]))
	{
		if (i < k * map->limits[Y] - k)
			line_renderer(&map->points[i], &map->points[i + k], data, scale);
		if (j++ < map->limits[X] - 1)
			line_renderer(&map->points[i], &map->points[i + 1], data, scale);
		else
			j = 0;
		i++;
	}
	// STARTS TOP LEFT
	line_renderer(&map->points[0], &map->points[37], data, scale);
	line_renderer(&map->points[0], &map->points[56], data, scale);
	line_renderer(&map->points[0], &map->points[75], data, scale);
	line_renderer(&map->points[0], &map->points[94], data, scale);
	line_renderer(&map->points[0], &map->points[113], data, scale);
	line_renderer(&map->points[0], &map->points[132], data, scale);
	line_renderer(&map->points[0], &map->points[151], data, scale);
	line_renderer(&map->points[0], &map->points[170], data, scale);
	line_renderer(&map->points[0], &map->points[189], data, scale);
	line_renderer(&map->points[0], &map->points[208], data, scale);
	// DY > DX
	line_renderer(&map->points[0], &map->points[191], data, scale);
	line_renderer(&map->points[0], &map->points[192], data, scale);
	line_renderer(&map->points[0], &map->points[193], data, scale);
	line_renderer(&map->points[0], &map->points[194], data, scale);
	line_renderer(&map->points[0], &map->points[195], data, scale);
	line_renderer(&map->points[0], &map->points[196], data, scale);
	line_renderer(&map->points[0], &map->points[197], data, scale);
	line_renderer(&map->points[0], &map->points[198], data, scale);
	// DX > DY
	line_renderer(&map->points[0], &map->points[199], data, scale);
	line_renderer(&map->points[0], &map->points[200], data, scale);
	line_renderer(&map->points[0], &map->points[201], data, scale);
	line_renderer(&map->points[0], &map->points[202], data, scale);
	line_renderer(&map->points[0], &map->points[203], data, scale);
	line_renderer(&map->points[0], &map->points[204], data, scale);
	line_renderer(&map->points[0], &map->points[205], data, scale);
	line_renderer(&map->points[0], &map->points[206], data, scale);
	line_renderer(&map->points[0], &map->points[207], data, scale);
	// STARTS TOP RIGHT
	line_renderer(&map->points[18], &map->points[19], data, scale);
	line_renderer(&map->points[18], &map->points[38], data, scale);
	line_renderer(&map->points[18], &map->points[57], data, scale);
	line_renderer(&map->points[18], &map->points[76], data, scale);
	line_renderer(&map->points[18], &map->points[95], data, scale);
	line_renderer(&map->points[18], &map->points[114], data, scale);
	line_renderer(&map->points[18], &map->points[133], data, scale);
	line_renderer(&map->points[18], &map->points[152], data, scale);
	line_renderer(&map->points[18], &map->points[171], data, scale);
	line_renderer(&map->points[18], &map->points[190], data, scale);
	// DY > DX
	line_renderer(&map->points[18], &map->points[0], data, scale);
	line_renderer(&map->points[18], &map->points[191], data, scale);
	line_renderer(&map->points[18], &map->points[192], data, scale);
	line_renderer(&map->points[18], &map->points[193], data, scale);
	line_renderer(&map->points[18], &map->points[194], data, scale);
	line_renderer(&map->points[18], &map->points[195], data, scale);
	line_renderer(&map->points[18], &map->points[196], data, scale);
	line_renderer(&map->points[18], &map->points[197], data, scale);
	// DX > DY
	line_renderer(&map->points[18], &map->points[198], data, scale);
	line_renderer(&map->points[18], &map->points[199], data, scale);
	line_renderer(&map->points[18], &map->points[200], data, scale);
	line_renderer(&map->points[18], &map->points[201], data, scale);
	line_renderer(&map->points[18], &map->points[202], data, scale);
	line_renderer(&map->points[18], &map->points[203], data, scale);
	line_renderer(&map->points[18], &map->points[204], data, scale);
	line_renderer(&map->points[18], &map->points[205], data, scale);
	line_renderer(&map->points[18], &map->points[206], data, scale);
	//STARTS BOTTOM LEFT
	// DY > DX
	line_renderer(&map->points[190], &map->points[1], data, scale);
	line_renderer(&map->points[190], &map->points[2], data, scale);
	line_renderer(&map->points[190], &map->points[3], data, scale);
	line_renderer(&map->points[190], &map->points[4], data, scale);
	line_renderer(&map->points[190], &map->points[5], data, scale);
	line_renderer(&map->points[190], &map->points[6], data, scale);
	line_renderer(&map->points[190], &map->points[7], data, scale);
	line_renderer(&map->points[190], &map->points[8], data, scale);
	line_renderer(&map->points[190], &map->points[9], data, scale);
	line_renderer(&map->points[190], &map->points[10], data, scale);
	// DX > DY
	line_renderer(&map->points[190], &map->points[11], data, scale);
	line_renderer(&map->points[190], &map->points[12], data, scale);
	line_renderer(&map->points[190], &map->points[13], data, scale);
	line_renderer(&map->points[190], &map->points[14], data, scale);
	line_renderer(&map->points[190], &map->points[15], data, scale);
	line_renderer(&map->points[190], &map->points[16], data, scale);
	line_renderer(&map->points[190], &map->points[17], data, scale);
	line_renderer(&map->points[190], &map->points[18], data, scale);
	//
	line_renderer(&map->points[190], &map->points[19], data, scale);
	line_renderer(&map->points[190], &map->points[38], data, scale);
	line_renderer(&map->points[190], &map->points[57], data, scale);
	line_renderer(&map->points[190], &map->points[76], data, scale);
	line_renderer(&map->points[190], &map->points[95], data, scale);
	line_renderer(&map->points[190], &map->points[114], data, scale);
	line_renderer(&map->points[190], &map->points[133], data, scale);
	line_renderer(&map->points[190], &map->points[152], data, scale);
	line_renderer(&map->points[190], &map->points[171], data, scale);
	// STARTS BOTTOM RIGHT
	line_renderer(&map->points[208], &map->points[0], data, scale);
	line_renderer(&map->points[208], &map->points[19], data, scale);
	line_renderer(&map->points[208], &map->points[38], data, scale);
	line_renderer(&map->points[208], &map->points[57], data, scale);
	line_renderer(&map->points[208], &map->points[76], data, scale);
	line_renderer(&map->points[208], &map->points[95], data, scale);
	line_renderer(&map->points[208], &map->points[114], data, scale);
	line_renderer(&map->points[208], &map->points[133], data, scale);
	line_renderer(&map->points[208], &map->points[152], data, scale);
	line_renderer(&map->points[208], &map->points[171], data, scale);
	// DY > DX
	line_renderer(&map->points[208], &map->points[1], data, scale);
	line_renderer(&map->points[208], &map->points[2], data, scale);
	line_renderer(&map->points[208], &map->points[3], data, scale);
	line_renderer(&map->points[208], &map->points[4], data, scale);
	line_renderer(&map->points[208], &map->points[5], data, scale);
	line_renderer(&map->points[208], &map->points[6], data, scale);
	line_renderer(&map->points[208], &map->points[7], data, scale);
	line_renderer(&map->points[208], &map->points[8], data, scale);
	// DX > DY
	line_renderer(&map->points[208], &map->points[9], data, scale);
	line_renderer(&map->points[208], &map->points[10], data, scale);
	line_renderer(&map->points[208], &map->points[11], data, scale);
	line_renderer(&map->points[208], &map->points[12], data, scale);
	line_renderer(&map->points[208], &map->points[13], data, scale);
	line_renderer(&map->points[208], &map->points[14], data, scale);
	line_renderer(&map->points[208], &map->points[15], data, scale);
	line_renderer(&map->points[208], &map->points[16], data, scale);
	line_renderer(&map->points[208], &map->points[17], data, scale);

	center_image(map, vars, data, scale);
	return (1);
}
