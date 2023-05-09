/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:11:28 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/09 12:54:47 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include "ft_printf.h"
#include "fdf.h"
#include "color_defs.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static void	start_mlx(t_vars *vars, t_data *data)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1920, 1080, "ffornes- Fdf");
	data->img = mlx_new_image(vars->mlx, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bpps, &data->l_len, &data->endian);
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, 0, 0);
}

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
	t_vars	vars;
	t_data	data;

	if (argc < 2 || argc > 2)
		return (0);
	load_map(&map, argv[1]);
	start_mlx(&vars, &data);
	// Whatever goes after initialization && hooks
	printf("Map limits: [%d X]  [%d Y]  [%d Z]\n", map.limits[X], map.limits[Y], map.limits[Z]);
	if (draw_screen(&map, &vars, &data) < 0)
		ft_printf("Error_4: Bad draw screen\n");
	// Hooks
	mlx_key_hook(vars.win, key_hook, &vars);
	// Loop
	mlx_loop(vars.mlx);
	// Frees
	free(map.fdf_file);
	free(map.points);
	return (0);
}

/*
	printf("Map limits: [%.2f X]  [%.2f Y]  [%.2f Z]\n", map.limits[X], map.limits[Y], map.limits[Z]);
*/
