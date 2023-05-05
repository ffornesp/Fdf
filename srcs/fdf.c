/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:11:28 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/05 16:35:30 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "color_defs.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/*
static void	check_points(t_point **points)
{
	int	i;
	int	j;

	i = 0;
	while (points[i])
	{
		j = 0;
		while (points[i][0].size_col > j)
			ft_printf("%d", points[i][j++].value);
		free(points[i++]);
		ft_printf("\n");
	}
	free(points);
}*/

void	load_map(t_map *map, char *fdf_file)
{
	int	fd;

	map_init(map);
	fd = open(fdf_file, O_RDONLY);
	map->fdf_file = parse_map(fd);
	close(fd);
	map_size(map);
	map_points(map);
}

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc < 2 || argc > 2)
		return (0);
	load_map(&map, argv[1]);
	free(map.fdf_file);
	printf("Map limits: [%.2f X]  [%.2f Y]  [%.2f Z]\n", map.limits[X], map.limits[Y], map.limits[Z]);
	printf("Map dimensions: %.2f x %.2f = %d\n\n", map.limits[X], map.limits[Y], map.len);
	printf("Random point parameters: [%2.f X]  [%2.f Y]  [%2.f Z]\n", map.points[41].pos[X], map.points[41].pos[Y], map.points[41].pos[Z]);
	free(map.points);
	return (0);
}

// Initialize structure map
//
// Open file
	// Check fd
	// Save map in char * in struct
// Close file
//
// Get map size (limits XYZ)
// Get map points
