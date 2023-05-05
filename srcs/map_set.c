/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:24:14 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/05 16:35:29 by ffornes-         ###   ########.fr       */
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

void	map_size(t_map *map)
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
				ft_printf("Error1: Limits X && elements are not equal\n");
			else
				map->limits[X] = elements;
			elements = 0;
		}
		i++;
	}
	if (map->limits[X] != 0 && map->limits[X] != elements)
		ft_printf("Error2: Limits X && elements are not equal\n");
	map->limits[Y]++;
	map->len = map->limits[X] * map->limits[Y];
}

void	map_points(t_map *map)
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
		while (j < map ->limits[X])
		{
			map->points[n].pos[X] = j;
			map->points[n].pos[Y] = i;
			map->points[n].pos[Z] = ft_atoi(s_line[j]);
			n++;
			j++;
			free(s_line[j]);
		}
		free(m_lines[i]);
		free(s_line);
		i++;
	}
	free(m_lines);
}
