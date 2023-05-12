/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:19:10 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/12 12:05:16 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "fdf.h"
#include "color_defs.h"
#include <stdlib.h>
#include <math.h>

static void	other_line(t_point *p, t_data *img)
{
	int		*k;
	t_point	aux;

	k = malloc(sizeof(int) * 2);
	if (p[1].pos[X] < p[0].pos[X])
	{
		aux = p[0];
		p[0] = p[1];
		p[1] = aux;
	}
	k[X] = p[1].pos[X] - p[0].pos[X];
	k[Y] = p[1].pos[Y] - p[0].pos[Y];
//	ft_printf("[X %d | Y %d]     [X %d | Y %d]\n", p[0].pos[X], p[0].pos[Y], p[1].pos[X], p[1].pos[Y]);
	calculate_line(k, p, img);
	free(k);
}

static void	straight_line(t_point p0, t_point p1, t_data *img)
{
	if (p0.pos[X] == p1.pos[X])
	{
		while (p0.pos[Y] < p1.pos[Y])
		{
			my_mlx_pixel_put(img, p0.pos[X], p0.pos[Y], BLUE);
			if (p0.pos[Y] < p1.pos[Y])
				p0.pos[Y]++;
			else
				p0.pos[Y]--;
		}
	}
	else
	{
		while (p0.pos[X] < p1.pos[X])
		{
			my_mlx_pixel_put(img, p0.pos[X], p0.pos[Y], GREEN);
			if (p0.pos[X] < p1.pos[X])
				p0.pos[X]++;
			else if (p0.pos[X] > p1.pos[X])
				p0.pos[X]--;
		}
	}
}

static t_point *calculate_line_limits(t_point *p0, t_point *p1, int scale)
{
	t_point	*p;

	p = malloc(sizeof(t_point) * 2);
	p[0] = *p0;
	p[1] = *p1;
	p[0].pos[X] = (p0->pos[X] * scale - p0->pos[Y] * scale) * cos(120);
	p[0].pos[Y] = (p0->pos[X] * scale + p0->pos[Y] * scale) * sin(120);
	p[0].pos[X] += 20 * scale;
	p[0].pos[Y] += p[0].pos[Z] * -4 + (scale * 3);
	p[1].pos[X] = (p1->pos[X] * scale - p1->pos[Y] * scale) * cos(120);
	p[1].pos[Y] = (p1->pos[X] * scale + p1->pos[Y] * scale) * sin(120);
	p[1].pos[X] += 20 * scale;
	p[1].pos[Y] += p[1].pos[Z] * -4 + (scale * 3);
	return (p);
}

void	line_renderer(t_point *p0, t_point *p1, t_data *img, int scale)
{
	t_point	*p;

	p = calculate_line_limits(p0, p1, scale);
//	ft_printf("[X %d | Y %d]     [X %d | Y %d]\n", p[0].pos[X], p[0].pos[Y], p[1].pos[X], p[1].pos[Y]);
	if (p[0].pos[X] == p[1].pos[X])
	{
		if (p[0].pos[Y] < p[1].pos[Y])
			straight_line(p[0], p[1], img);
		else
			straight_line(p[1], p[0], img);
	}
	else if (p[0].pos[Y] ==  p[1].pos[Y])
	{
		if (p[0].pos[X] < p[1].pos[X])
			straight_line(p[0], p[1], img);
		else
			straight_line(p[1], p[0], img);
	}
	else
		other_line(p, img);
	free(p);
}
