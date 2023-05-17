/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_scale.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:00:12 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/17 14:52:46 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	calculate_scale_z(float scale)
{
	float	scale_z;

	scale_z = -2.5f;
	if (scale > 13.3f && scale < 13.5f)
		return (scale_z * 2);
	if (scale > 23.0f && scale < 23.2f)
		return (-10);
	if (scale < 1.5f && scale > 1.1f)
		scale_z /= 2;
	else if (scale <= 1.1f)
		scale_z /= 4;
	return (scale_z);
}

void	calculate_scale(t_map *map, float *scale, t_point pos0)
{
	scale[0] = 1;
	while ((map->limits[X] + map->limits[X] / 2)
		* scale[0] + pos0.pos[X] < WIDTH)
		scale[0] += 0.1f;
	if (map->limits[Z] < 270)
	{
		while ((map->limits[Y] * scale[0])
			+ (map->limits[Z] * 2.5f) + pos0.pos[Y] > HEIGHT && scale[0] > 0)
			scale[0] -= 0.1f;
	}
	if (map->limits[Z] > 200)
	{
		if (map->limits[X] >= 200 && map->limits[Y] >= 200)
			scale[0] = 2;
	}
	else if (map->limits[Z] > 150
		&& map->limits[X] >= 100 && map->limits[Y] >= 100)
		scale[0] = 4;
	scale[1] = calculate_scale_z(scale[0]);
}
