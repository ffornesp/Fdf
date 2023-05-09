/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:19:10 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/09 10:31:15 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "fdf.h"
#include "color_defs.h"
#include <stdlib.h>
#include <stdio.h>

/*
static void	other_line(t_point p0, t_point p1, t_data *img)
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	
	dx = p1.pos[X] - p0.pos[X];
	dy = p1.pos[Y] - p0.pos[Y];
	x = p0.pos[X];
	y = (dy / dx) * (float)(x - p0.pos[X]) + (float)p0.pos[Y];
	while (x < p1.pos[X] && y < p1.pos[Y])
	{
		if (dx >= dy)
		{
			y += (dy / dx);
			my_mlx_pixel_put(img, x, y, GREEN);
			x++;
		}
		else
		{
			x += (dx / dy);
			my_mlx_pixel_put(img, x, y, RED);
			y++;
		}
	}
}*/

static void	straight_line(t_point *p0, t_point *p1, t_data *img)
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;

	x0 = (int)p0->pos[X] * 40;
	y0 = (int)p0->pos[Y] * 40;
	x1 = (int)p1->pos[X] * 40;
	y1 = (int)p1->pos[Y] * 40;
	if (x0 == x1) // VERTICAL
	{
		while (y0 != y1)
		{
			my_mlx_pixel_put(img, x0, y0, BLUE);
			if (y0 < y1)
				y0++;
			else
				y0--;
		}
	}
	else if (y0 == y1)
	{
		while (x0 != x1)
		{
			my_mlx_pixel_put(img, x0, y0, GREEN);
			if (x0 < x1)
				x0++;
			else if (x0 > x1)
				x0--;
		}
	}
}

void	line_renderer(t_point *p0, t_point *p1, t_data *img)
{
	if (p0->pos[X] == p1->pos[X] || p0->pos[Y] == p1->pos[Y])
		straight_line(p0, p1, img);
//	else if (p0->pos[X] < p1->pos[X])
//		other_line(*p0, *p1, img);
//	else
//		other_line(*p1, *p0, img);
}
