/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:24:14 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/16 17:42:21 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include <stdlib.h>

void	map_init(t_map *map)
{
	map->limits[X] = 0;
	map->limits[Y] = 0;
	map->limits[Z] = 0;
	map->len = 0;
	map->min_d[X] = WIDTH / 2;
	map->min_d[Y] = HEIGHT / 2;
	map->max_d[X] = WIDTH / 2;
	map->max_d[Y] = HEIGHT / 2;
}

void	map_set_size(t_map *map)
{
	int	i;
	int	elements;

	i = 0;
	elements = 0;
	while (map->fdf_file[i])
	{
		if (ft_isalnum(map->fdf_file[i]) && (map->fdf_file[i + 1] == ' '
				|| map->fdf_file[i + 1] == '\n'
				|| map->fdf_file[i + 1] == '\0'))
				elements++;
		if (map->fdf_file[i] == '\n' && map->fdf_file[i + 1] != '\0')
		{
			map->limits[Y]++;
			if (map->limits[X] != 0 && map->limits[X] != elements)
				ft_putstr_fd("Error_1: Limits X && elements are not equal\n", 2);
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
