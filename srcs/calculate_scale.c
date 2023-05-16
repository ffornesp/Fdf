/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_scale.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:00:12 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/16 11:31:40 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

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

void	calculate_scale(t_map *map, float *scale)
{
	scale[0] = 1;
	while ((map->limits[X] + map->limits[X] / 2) * scale[0] + 960 < WIDTH)
		scale[0] += 0.1f;
	while ((map->limits[Y] * scale[0]) + (map->limits[Z] * 2.5f) + 270 > HEIGHT)
		scale[0] -= 0.1f;
	if (scale[0] <= 0)
		scale[0] = 0;
	if (map->limits[Z] > 200)
	{
		if (map->limits[X] >= 200 && map->limits[Y] >= 200)
			scale[0] = 2;
	}
	else if (map->limits[Z] > 150)
	{
		if (map->limits[X] >= 200 && map->limits[Y] >= 200)
			scale[0] = 5;
	}
	scale[1] = calculate_scale_z(scale[0]);
}
