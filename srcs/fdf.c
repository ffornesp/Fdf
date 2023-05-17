/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:11:28 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/17 14:43:26 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static void	start_mlx(t_vars *vars, t_data *d)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1920, 1080, "ffornes- Fdf");
	d->img = mlx_new_image(vars->mlx, 1920, 1080);
	d->addr = mlx_get_data_addr(d->img, &d->bpps, &d->l_len, &d->endian);
	mlx_put_image_to_window(vars->mlx, vars->win, d->img, 0, 0);
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
	char	*aux;

	if (argc < 2 || argc > 2)
		return (0);
	aux = argv[1] + ft_strlen(argv[1]) - 4;
	if (ft_strncmp(aux, ".fdf", 4))
	{
		ft_putstr_fd("Error: File is not valid\n", 2);
		return (0);
	}
	load_map(&map, argv[1]);
	start_mlx(&vars, &data);
	if (draw_screen(&map, &vars, &data) < 0)
		ft_putstr_fd("Error: Not able to draw screen\n", 2);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, finish_execution, &vars);
	mlx_loop(vars.mlx);
	free(map.fdf_file);
	free(map.points);
	return (0);
}
