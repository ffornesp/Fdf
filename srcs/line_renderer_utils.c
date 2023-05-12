/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_renderer_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:04:21 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/12 12:10:30 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
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
	if (k[Y] < 0 && -k[Y] < k[X])
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
		if (*d >= 0)
			*d -= 2 * k[X];
		else
		{
			*d += 2 * (-k[X] - k[Y]);
			p[0].pos[X]++;
		}
	}
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
			my_mlx_pixel_put(img, p[0].pos[X], p[0].pos[Y], RED);
			line_case_1(&d, k, p);
		}
	}
	else
	{
		d = 2 * (k[X] + k[Y]);
		if (-k[Y] > k[X])
			d = 2 * (-k[Y] + k[X]);
		while (p[0].pos[X] <= p[1].pos[X] && p[0].pos[Y] >= p[1].pos[Y])
		{
			my_mlx_pixel_put(img, p[0].pos[X], p[0].pos[Y], RED);
			line_case_2(&d, k, p);
		}
	}
}
