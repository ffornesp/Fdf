/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:12:09 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/15 18:26:29 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "color_defs.h"
#include "mlx.h"
#include <stdlib.h>
#include <math.h>

static float	calculate_scale(t_map *map)
{
	float	scale;

	scale = 1;
	while ((map->limits[X] + map->limits[X] / 2) * scale + 960 < 1920)
		scale += 0.1f;
	while ((map->limits[Y] * scale) + (map->limits[Z] * 2.5f) + 270 > 1080)
		scale -= 0.1f;
	if (scale > 0)
		return (scale);
	return (1);
}

static float	calculate_scale_z(float scale)
{
	float	scale_z;

	scale_z = -2.5f;

	if (scale < 1.5f)
		scale_z /= 2;
	if (scale > 5 && scale < 25)
		scale_z *= 4;
	return (scale_z);
}

int	draw_screen(t_map *map, t_vars *vars, t_data *data)
{
	int		i;
	int		j;
	int		k;
	float	*scale;

	i = 0;
	j = 0;
	scale = malloc(sizeof(int) * 2);
	scale[0] = calculate_scale(map);
	scale[1] = calculate_scale_z(scale[0]);
	k = map->limits[X];
	while (i < (map->limits[X] * map->limits[Y]))
	{
		if (i < map->limits[X] * map->limits[Y] - map->limits[X])
			line_renderer(&map->points[i], &map->points[i] + map->limits[X], data, scale);
		if (j++ < map->limits[X] - 1)
			line_renderer(&map->points[i], &map->points[i + 1], data, scale);
		else
			j = 0;
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);
	free(scale);
	return (1);
}
