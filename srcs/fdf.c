/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:11:28 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/05 17:18:15 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	load_map(t_map *map, char *fdf_file)
{
	int	fd;

	map_init(map);
	fd = open(fdf_file, O_RDONLY);
	map->fdf_file = parse_map(fd);
	close(fd);
	map_set_size(map);
	map_set_points(map);
}

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc < 2 || argc > 2)
		return (0);
	load_map(&map, argv[1]);
	free(map.fdf_file);
	printf("Map limits: [%.2f X]  [%.2f Y]  [%.2f Z]\n", map.limits[X], map.limits[Y], map.limits[Z]);
	printf("Random point parameters: [%2.f X]  [%2.f Y]  [%2.f Z]\n", map.points[2].pos[X], map.points[2].pos[Y], map.points[2].pos[Z]);
	free(map.points);
	return (0);
}
