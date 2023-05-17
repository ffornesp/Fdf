/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:12:09 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/17 14:45:29 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
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

static void	get_limits_1(t_map *map, t_point p, float *scale, t_point pos0)
{
	int	aux;
	int	tmp1;
	int	tmp2;

	tmp1 = p.pos[X] * scale[0];
	tmp2 = p.pos[Y] * scale[0];
	aux = (tmp1 - tmp2) * cos(120);
	aux += pos0.pos[X];
	if (aux < map->min_d[X])
		map->min_d[X] = aux;
	else if (aux > map->max_d[X])
		map->max_d[X] = aux;
	aux = (tmp1 + tmp2) * sin(120);
	aux += p.pos[Z] * scale[1] + pos0.pos[Y];
	if (aux < map->min_d[Y])
		map->min_d[Y] = aux;
	else if (aux > map->max_d[Y])
		map->max_d[Y] = aux;
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
		get_limits_1(map, map->points[i], scale, pos0);
		if (i < map->limits[X] * map->limits[Y] - map->limits[X])
		{
			get_points(map->points[i], map->points[i + k], scale, p);
			line_renderer(p, data, scale, pos0);
		}
		get_points(map->points[i], map->points[i + 1], scale, p);
		if (j++ < map->limits[X] - 1)
			line_renderer(p, data, scale, pos0);
		else
			j = 0;
		i++;
	}
	free(p);
}

int	draw_screen(t_map *map, t_vars *vars, t_data *data)
{
	float	*scale;
	t_point	pos0;
	int		move_x;
	int		move_y;

	scale = malloc(sizeof(float) * 2);
	pos0.pos[X] = WIDTH / 2;
	pos0.pos[Y] = HEIGHT / 4;
	calculate_scale(map, scale, pos0);
	if (map->limits[Z] > 200)
	{
		if (map->limits[X] > 150 && map->limits[Y] > 150)
			pos0.pos[Y] = HEIGHT / 2;
	}
	draw_points(map, data, scale, pos0);
	move_x = map->min_d[X] - ((WIDTH - (map->max_d[X] - map->min_d[X])) / 2);
	move_y = map->min_d[Y] - ((HEIGHT - (map->max_d[Y] - map->min_d[Y])) / 2);
	if (map->limits[X] > WIDTH / (4 / 3))
		move_x = 0;
	if (map->limits[Z] > HEIGHT / (4 / 3)
		|| map->limits[Y] > HEIGHT / (4 / 3))
		move_y = 0;
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, -move_x, -move_y);
	free(scale);
	return (1);
}
