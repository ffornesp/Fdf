/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:12:09 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/15 11:55:52 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "fdf.h"
#include "color_defs.h"
#include "mlx.h"
#include <math.h>

/*static void	center_image(t_map *map, t_vars *vars, t_data *data, int scale)
{
	int	s1;
	int	s2;

	s1 = (1920 - map->limits[X] * scale) / 2;
	s2 = (1080 - map->limits[Y] * scale) / 2;
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, s1, s2);
}*/

static int	calculate_scale(int win_size, t_map *map)
{
	int	scale;

	scale = 1;
	while ((map->limits[X] - 1) * scale < win_size / 3)
		scale++;
	return (scale--);
	//else invert axis of calculation
}

int	draw_screen(t_map *map, t_vars *vars, t_data *data)
{
	int	i;
	int	j;
	int	k;
	int	scale;

	i = 0;
	j = 0;
	scale = calculate_scale(1920, map);
	ft_printf("Scale is: %d\n", scale);
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
