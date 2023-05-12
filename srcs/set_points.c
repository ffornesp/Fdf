/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:41:07 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/12 16:28:51 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "fdf.h"
#include <stdlib.h>

static void	set_point_coords(t_point *point, int x, int y, char *line)
{
	int		i;

	point->pos[X] = x;
	point->pos[Y] = y;
	point->pos[Z] = ft_atoi(line);
	if (ft_strchr(line, ','))
	{
		i = 0;
		while (*(line + i) != 'x')
			i++;
		i++;
		point->color = ft_atoi_base((line + i), 16);
	}
}

static void	set_limit_z(t_map *map)
{
	int		i;
	float	min;
	float	max;

	i = 0;
	min = map->points[i].pos[Z];
	max = map->points[i].pos[Z];
	while (i < (map->limits[X] * map->limits[Y]))
	{
		if (min > map->points[i].pos[Z])
			min = map->points[i].pos[Z];
		else if (max < map->points[i].pos[Z])
			max = map->points[i].pos[Z];
		i++;
	}
	map->limits[Z] = (min * -1) + max;
}

void	map_set_points(t_map *map)
{
	int		i;
	int		j;
	int		n;
	char	**m_lines;
	char	**s_line;

	i = 0;
	n = 0;
	map->points = ft_calloc(map->len, sizeof(t_point));
	m_lines = ft_split(map->fdf_file, '\n');
	while (i < map->limits[Y])
	{
		s_line = ft_split(m_lines[i], ' ');
		j = 0;
		while (j < map->limits[X])
		{
			set_point_coords(&map->points[n++], j, i, s_line[j]);
			free(s_line[j++]);
		}
		free(m_lines[i]);
		free(s_line);
		i++;
	}
	set_limit_z(map);
	free(m_lines);
}
