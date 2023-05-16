/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:12:09 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/16 14:45:37 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"
#include "color_defs.h"
#include "mlx.h"
#include <math.h>
#include <stdlib.h>

static t_point	*get_points(t_point p0, t_point p1, float *scale, t_point *p)
{
	p[0] = p0;
	p[1] = p1;
	p[0].pos[X] *= scale[0];
	p[0].pos[Y] *= scale[0];
	p[1].pos[X] *= scale[0];
	p[1].pos[Y] *= scale[0];
	return (p);
}

static void	draw_points(t_map *map, t_data *data, float *scale, t_point pos0)
{
	int		i;
	int		j;
	int		k;
	t_point	*p;

	i = 0;
	j = 0;
	k = map->limits[X];
	p = malloc(sizeof(t_point) * 2);
	while (i < (map->limits[X] * map->limits[Y]))
	{
		if (i < map->limits[X] * map->limits[Y] - map->limits[X])
		{
			get_points(map->points[i], map->points[i + k], scale, p);
			line_renderer(p, data, scale, pos0);
		}
		if (j++ < map->limits[X] - 1)
		{
			get_points(map->points[i], map->points[i + 1], scale, p);
			line_renderer(p, data, scale, pos0);
		}
		else
			j = 0;
		i++;
	}
	free(p);
}

static void	get_limits_drawn(t_map *map, t_point pos0, float *scale)
{
	int	i;
	int	aux;

	i = 0;
	map->min_d[X] = 960;
	map->min_d[Y] = 540;
	while (i < (map->limits[X] * map->limits[Y]))
	{
		map->points[i].pos[X] *= scale[0];
		map->points[i].pos[Y] *= scale[0];
		aux = (map->points[i].pos[X] - map->points[i].pos[Y]) * cos(120);
		aux += pos0.pos[X];
		if (aux < map->min_d[X])
			map->min_d[X] = aux;
		else if (aux > map->max_d[X])
			map->max_d[X] = aux;
		aux = (map->points[i].pos[X] + map->points[i].pos[Y]) * sin(120);
		aux += map->points[i].pos[Z] * scale[1] + pos0.pos[Y];
		if (aux < map->min_d[Y])
			map->min_d[Y] = aux;
		else if (aux > map->max_d[Y])
			map->max_d[Y] = aux;	
		i++;
	}
}

int	draw_screen(t_map *map, t_vars *vars, t_data *data)
{
	float	*scale;
	t_point	pos0;
	int		move_x;
	int		move_y;

	scale = malloc(sizeof(float) * 2);
	calculate_scale(map, scale);
	pos0.pos[X] = WIDTH / 2;
	pos0.pos[Y] = HEIGHT / 4;
	if (map->limits[Z] > 200)
	{
		if (map->limits[X] > 150 && map->limits[Y] > 150)
			pos0.pos[Y] = HEIGHT / 2;
	}
	draw_points(map, data, scale, pos0);
	get_limits_drawn(map, pos0, scale);
	printf("Min [X %d] [Y %d] | ", map->min_d[X], map->min_d[Y]);
	printf("Max [X %d] [Y %d]\n", map->max_d[X], map->max_d[Y]);
	move_x = map->max_d[X] - map->min_d[X];
	move_x = (WIDTH - move_x) / 2;
	move_x = map->min_d[X] - move_x;
	move_x *= -1;
	move_y = 0;
	printf("MoveX %d, MoveY %d\n", move_x, move_y);
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, move_x, 0);
	free(scale);
	return (1);
}
