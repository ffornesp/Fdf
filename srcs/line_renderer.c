/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_renderer_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:19:10 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/16 17:01:12 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	modify_points(t_point *p0, t_point *p1, int id)
{
	if (id)
	{
		if (p0->pos[X] < p1->pos[X])
			p0->pos[X]++;
		else
			p0->pos[X]--;
	}
	else
	{
		if (p0->pos[Y] < p1->pos[Y])
			p0->pos[Y]++;
		else
			p0->pos[Y]--;
	}
}

static void	straight_line(t_point *p, t_data *img)
{
	int	color;

	color = WHITE;
	if (p[0].color == p[1].color)
		color = p[0].color;
	if (p[0].pos[X] == p[1].pos[X])
	{
		while (p[0].pos[Y] < p[1].pos[Y])
		{
			draw_check(p, img, color);
			modify_points(&p[0], &p[1], 0);
		}
	}
	else
	{
		while (p[0].pos[X] < p[1].pos[X])
		{
			draw_check(p, img, color);
			modify_points(&p[0], &p[1], 1);
		}
	}
}

static t_point	*calculate_line_limits(t_point *p, float *scale, t_point pos0)
{
	t_point	a;
	t_point	b;

	a = p[0];
	b = p[1];
	p[0].pos[X] = (a.pos[X] - a.pos[Y]) * cos(120);
	p[0].pos[Y] = (a.pos[X] + a.pos[Y]) * sin(120);
	p[1].pos[X] = (b.pos[X] - b.pos[Y]) * cos(120);
	p[1].pos[Y] = (b.pos[X] + b.pos[Y]) * sin(120);
	p[0].pos[X] += pos0.pos[X];
	p[1].pos[X] += pos0.pos[X];
	p[0].pos[Y] += p[0].pos[Z] * scale[1] + pos0.pos[Y];
	p[1].pos[Y] += p[1].pos[Z] * scale[1] + pos0.pos[Y];
	return (p);
}

void	line_renderer(t_point *p, t_data *img, float *scale, t_point pos0)
{
	p = calculate_line_limits(p, scale, pos0);
	if (p[0].pos[X] == p[1].pos[X])
	{
		if (p[0].pos[Y] < p[1].pos[Y])
			straight_line(p, img);
		else
			straight_line(p, img);
	}
	else if (p[0].pos[Y] == p[1].pos[Y])
	{
		if (p[0].pos[X] < p[1].pos[X])
			straight_line(p, img);
		else
			straight_line(p, img);
	}
	else
		other_line(p, img);
}
