/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:19:10 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/05 14:57:40 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "color_defs.h"
#include <stdlib.h>

static void	other_line(int *p0, int *p1, t_data img)
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	
	dx = p1[0] - p0[0];
	dy = p1[1] - p0[1];
	x = p0[0];
	y = (dy / dx) * (float)(x - p0[0]) + (float)p0[1];
	while (x < p1[0] && y < p1[1])
	{
		if (dx >= dy)
		{
			y += (dy / dx);
			my_mlx_pixel_put(&img, x, y, GREEN);
			x++;
		}
		else
		{
			x += (dx / dy);
			my_mlx_pixel_put(&img, x, y, RED);
			y++;
		}
	}
}

static void	straight_line(int *p0, int *p1, t_data img)
{
	if (p0[0] == p1[0])
	{
		while (p0[1] != p1[1])
		{
			my_mlx_pixel_put(&img, p0[0], p0[1], BLUE);
			if (p0[1] < p1[1])
				p0[1]++;
			else
				p0[1]--;
		}
	}
	else if (p0[1] == p1[1])
	{
		while (p0[0] != p1[0])
		{
			my_mlx_pixel_put(&img, p0[0], p0[1], GREEN);
			if (p0[0] < p1[0])
				p0[0]++;
			else
				p0[0]--;
		}
	}
}

void	line_renderer(int *p0, int *p1, t_data img)
{
	if (p0[0] == p1[0] || p0[1] == p1[1])
		straight_line(p0, p1, img);
	else if (p0[0] < p1[0])
		other_line(p0, p1, img);
	else
		other_line(p1, p0, img);
}
