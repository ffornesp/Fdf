/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:12:09 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/11 20:23:44 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "fdf.h"
#include "color_defs.h"
#include "mlx.h"
#include <math.h>

/* 		To center image: 
* 		(WINDOW_SIZE_X - IMAGE_SIZE_X) / 2 ... (WINDOW_SIZE_Y - IMAGE_SIZE_Y) / 2
* 		where IMAGE_SIZE is MAP_LIMITS_X * SCALE
*
static void	center_image(t_map *map, t_vars *vars, t_data *data, int scale)
{
	int	s1;
	int	s2;

	s1 = (1920 - map->limits[X] * scale) / 2;
	s2 = (1080 - map->limits[Y] * scale) / 2;
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, s1, s2);
}*/

int	draw_screen(t_map *map, t_vars *vars, t_data *data)
{
	int	i;
	int	j;
	int	k;
	int	scale;

	i = 0;
	j = 0;
	scale = 40;
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
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);
	//center_image(map, vars, data, scale);
	return (1);
}
