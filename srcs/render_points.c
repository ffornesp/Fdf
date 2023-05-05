/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:41:23 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/05 13:59:55 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "color_defs.h"
#include <stdlib.h>

void	render_points(t_point **points, t_data img)
{
	int	i;
	int	j;
	int	*p1;
	int	*p2;

	i = 0;
	j = 0;
	p1 = malloc(sizeof(int) * 2);
	p2 = malloc(sizeof(int) * 2);
	while (points[i])
	{
		j = 0;
		while(points[i][0].size_col > j)
		{
			p1[0] = j * 15;
			p1[1] = i * 15;
			if (points[i][j].value > 0)
				my_mlx_pixel_put(&img, p1[0], p1[1], GREEN);
			else
				my_mlx_pixel_put(&img, p1[0], p1[1], RED);
			if (points[i])
			{
				p2[0] = j * 15;
				p2[1] = (i + 1) * 15;
				line_renderer(p1, p2, img);
			}
			if (points[i][0].size_col > j)
			{
				p2[0] = (j + 1) * 15;
				p2[1] = i * 15;
				line_renderer(p1, p2, img);
			}
			j++;
		}
		i++;
	}
	free(p1);
	free(p2);
}
