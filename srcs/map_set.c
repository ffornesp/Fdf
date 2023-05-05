/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:24:14 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/05 17:13:38 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "fdf.h"
#include <stdlib.h>

void	map_init(t_map *map)
{
	map->limits[X] = 0;
	map->limits[Y] = 0;
	map->limits[Z] = 0;
	map->len = 0;
}

void	map_set_size(t_map *map)
{
	int	i;
	int	elements;

	i = 0;
	elements = 0;
	while (map->fdf_file[i])
	{
		if (map->fdf_file[i] == '\n' && map->fdf_file[i + 1] == '\0')
			break ;
		if (ft_isalnum(map->fdf_file[i]) && (map->fdf_file[i + 1] == ' ' 
			|| map->fdf_file[i + 1] == '\n' || map->fdf_file[i + 1] == '\0'))
				elements++;
		if (map->fdf_file[i] == '\n')
		{
			map->limits[Y]++;
			if (map->limits[X] != 0 && map->limits[X] != elements)
				ft_putstr_fd("Error_1: Limits X && elements are not equal\n", 2);
			else
				map->limits[X] = elements;
			elements = 0;
		}
		i++;
	}
	if (map->limits[X] != 0 && map->limits[X] != elements)
		ft_putstr_fd("Error_2: Limits X && elements are not equal\n", 2);
	map->limits[Y]++;
	map->len = map->limits[X] * map->limits[Y];
}

static void	set_point_coords(t_point *point, int x, int y, char *line)
{
	point->pos[X] = x;
	point->pos[Y] = y;
	if (!ft_strchr(line, ','))
		point->pos[Z] = ft_atoi(line);
	else
	{
		ft_putstr_fd("Error_3: This map contains color info\n", 2);
	}
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
		free(m_lines[i++]);
		free(s_line);
	}
	free(m_lines);
}
