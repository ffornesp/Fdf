/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_renderer_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:04:21 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/17 15:24:50 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "color_defs.h"

static void	line_case_1(int *d, int *k, t_point *p)
{
	if (k[X] > k[Y])
	{
		p[0].pos[X]++;
		if (*d <= 0)
			*d += 2 * k[Y];
		else
		{
			*d += 2 * (k[Y] - k[X]);
			p[0].pos[Y]++;
		}
	}
	else
	{
		p[0].pos[Y]++;
		if (*d <= 0)
			*d += 2 * k[X];
		else
		{
			*d += 2 * (k[X] - k[Y]);
			p[0].pos[X]++;
		}
	}
}

static void	line_case_2(int *d, int *k, t_point *p)
{
	if (k[Y] < 0 && -1 * k[Y] < k[X])
	{
		p[0].pos[X]++;
		if (*d > 0)
			*d += 2 * k[Y];
		else
		{
			*d += 2 * (k[X] + k[Y]);
			p[0].pos[Y]--;
		}
	}
	else
	{
		p[0].pos[Y]--;
		if (*d > 0)
			*d -= 2 * k[X];
		else
		{
			*d += 2 * (-k[X] - k[Y]);
			p[0].pos[X]++;
		}
	}
}

static int	get_color(t_point *p)
{
	if (p[0].color != WHITE)
		return (p[0].color);
	else if (p[1].color != WHITE)
		return (p[1].color);
	return (WHITE);
}

void	draw_check(t_point *p, t_data *img, int color)
{
	if (p[0].pos[X] >= 0 && p[0].pos[X] < WIDTH
		&& p[0].pos[Y] >= 0 && p[0].pos[Y] < HEIGHT)
		my_mlx_pixel_put(img, p[0].pos[X], p[0].pos[Y], color);
}

void	calculate_line(int *k, t_point *p, t_data *img)
{
	int	d;

	if (p[0].pos[Y] < p[1].pos[Y])
	{
		d = 2 * k[Y] - k[X];
		if (k[Y] > k[X])
			d = 2 * k[X] - k[Y];
		while (p[0].pos[X] <= p[1].pos[X] && p[0].pos[Y] <= p[1].pos[Y])
		{
			draw_check(p, img, get_color(p));
			line_case_1(&d, k, p);
		}
	}
	else
	{
		d = 2 * (k[X] - k[X]);
		if (k[Y] < 0 && -1 * k[Y] < k[X])
			d = 2 * (k[X] + k[Y]);
		while (p[0].pos[X] <= p[1].pos[X] && p[0].pos[Y] >= p[1].pos[Y])
		{
			draw_check(p, img, get_color(p));
			line_case_2(&d, k, p);
		}
	}
}
