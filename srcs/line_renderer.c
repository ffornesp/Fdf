/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:19:10 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/08 17:57:22 by ffornes-         ###   ########.fr       */
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
	float	x;
	float	y;

	x = p0->pos[X];
	y = p0->pos[Y];
	if (p0->pos[X] == p1->pos[X]) // VERTICAL
	{
		while (y != p1->pos[Y])
		{
			my_mlx_pixel_put(img, p0->pos[X], p0->pos[Y], BLUE);
			if (y < p1->pos[Y])
				y++;
			else
				y--;
		}
	}
	else if (p0->pos[Y] == p1->pos[Y])
	{
		while (x <= p1->pos[X])
		{
			printf("X0 = %f, X1 = %f\n", x, p1->pos[X]);
			my_mlx_pixel_put(img, x, y, GREEN);
			if (x < p1->pos[X])
				x++;
			else if (x > p1->pos[X])
				x--;
			else
				break ;
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
