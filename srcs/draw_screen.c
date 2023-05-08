/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:12:09 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/08 17:11:06 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "fdf.h"
#include "color_defs.h"
#include "mlx.h"

int	draw_screen(t_map *map, t_vars *vars, t_data *data)
{
	int	x;
	int	y;
	int	i;
	
	i = 0;
	while (i < (map->limits[X] * map->limits[Y]))
	{
		if (i == 0)
		{
			ft_printf("HEllo\n");
			line_renderer(&map->points[i], &map->points[i + 1], data);
			line_renderer(&map->points[i], &map->points[i + 19], data);
		}
		else
		{
			x = map->points[i].pos[X] * 40;
			y = map->points[i].pos[Y] * 40;
			if (map->points[i].pos[Z] > 0)
				my_mlx_pixel_put(data, x, y, RED);
			else
				my_mlx_pixel_put(data, x, y, GREEN);
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, 10, 10);
	return (1);
}
