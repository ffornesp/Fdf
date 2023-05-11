/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:19:10 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/11 13:26:22 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "fdf.h"
#include "color_defs.h"
#include <stdlib.h>
#include <math.h>

static void	other_line(t_point p0, t_point p1, t_data *img, int scale)
{
	int		*k;
	t_point	*p;

	p0.pos[X] *= scale;
	p0.pos[Y] *= scale;
	p1.pos[X] *= scale;
	p1.pos[Y] *= scale;
	k = malloc(sizeof(int) * 2);
	k[X] = p1.pos[X] - p0.pos[X];
	k[Y] = p1.pos[Y] - p0.pos[Y];
	p = malloc(sizeof(t_point) * 2);
	p[0] = p0;
	p[1] = p1;
	calculate_line(k, p, img);
	free(k);
	free(p);
}

static void	straight_line(t_point p0, t_point p1, t_data *img, int scale)
{
	p0.pos[X] *= scale;
	p0.pos[Y] *= scale;
	p1.pos[X] *= scale;
	p1.pos[Y] *= scale;
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

void	line_renderer(t_point *p0, t_point *p1, t_data *img, int scale)
{
	if (p0->pos[X] == p1->pos[X])
	{
		if (p0->pos[Y] < p1->pos[Y])
			straight_line(*p0, *p1, img, scale);
		else
			straight_line(*p1, *p0, img, scale);
	}
	else if (p0->pos[Y] ==  p1->pos[Y])
	{
		if (p0->pos[X] < p1->pos[X])
			straight_line(*p0, *p1, img, scale);
		else
			straight_line(*p1, *p0, img, scale);
	}
	else if (p0->pos[X] < p1->pos[X])
		other_line(*p0, *p1, img, scale);
	else
		other_line(*p1, *p0, img, scale);
}
