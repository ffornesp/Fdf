/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:19:10 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/12 17:29:29 by ffornes-         ###   ########.fr       */
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
	t_point a;
	t_point b;

	p = malloc(sizeof(t_point) * 2);
	p[0] = *p0;
	p[1] = *p1;
	p[0].pos[X] *= scale;
	p[0].pos[Y] *= scale;
	p[1].pos[X] *= scale;
	p[1].pos[Y] *= scale;
	a = p[0];
	b = p[1];
	p[0].pos[X] = (a.pos[X] - a.pos[Y]) * cos(120);
	p[0].pos[Y] = (a.pos[X] + a.pos[Y]) * sin(120);
	p[1].pos[X] = (b.pos[X] - b.pos[Y]) * cos(120);
	p[1].pos[Y] = (b.pos[X] + b.pos[Y]) * sin(120);
	p[0].pos[X] += 1920 / 2;
	p[1].pos[X] += 1920 / 2;
	p[0].pos[Y] += p[0].pos[Z] * -3 + 1080 / 2;
	p[1].pos[Y] += p[1].pos[Z] * -3 + 1080 / 2;
	return (p);
}

void	line_renderer(t_point *p0, t_point *p1, t_data *img, int scale)
{
	t_point	*p;

	p = calculate_line_limits(p0, p1, scale);
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
