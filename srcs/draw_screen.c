/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:12:09 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/09 10:49:45 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "fdf.h"
#include "color_defs.h"
#include "mlx.h"

int	draw_screen(t_map *map, t_vars *vars, t_data *data)
{
	int	x;
	int	y;
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = map->limits[X];
	while (i < (map->limits[X] * map->limits[Y]))
	{
		// Al posar els punts d'aquesta manera i fer els calculs aqui fora a l'hora d'imprimir-los
		// passa que quan vull fer linies, no tinc en compte la nova distancia entre punts sino
		// que nomes tinc en compte la distancia aqui que es de diff 1. Bona sort
		x = map->points[i].pos[X] * 40;
		y = map->points[i].pos[Y] * 40;
		if (i < k * map->limits[Y] - k)
			line_renderer(&map->points[i], &map->points[i + k], data);
		if (j < map->limits[X] - 1)
		{
			line_renderer(&map->points[i], &map->points[i + 1], data);
			j++;
		}
		else
			j = 0;
		if (map->points[i].pos[Z] > 0)
			my_mlx_pixel_put(data, x, y, RED); // No fer servir pixel put i fer servir putimgtowindow
		else
			my_mlx_pixel_put(data, x, y, GREEN);
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, data->img, 10, 10);
	return (1);
}
