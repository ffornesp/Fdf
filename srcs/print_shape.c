/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:48:29 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/02 17:55:14 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "color_defs.h"

void	print_square(t_data img, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < x && j < y)
	{
		if (i >= 825 && i <= 1095 && j >= 405 && j <= 675)
			my_mlx_pixel_put(&img, i, j, color);
		else
			my_mlx_pixel_put(&img, i, j, BLACK);
		i++;
		if (i == x)
		{
			i = 0;
			j++;
		}
	}
}

void	print_triangle(t_data img, int x, int y, int color)
{
	int	i;
	int	j;
	int	min_x;
	int	max_x;
	int	n;

	i = 0;
	j = 0;
	n = 0;
	min_x = 420;
	max_x = 420;
	while (i < x && j < y)
	{
		if (i >= min_x && i <= max_x && j >= 405 && j <= 675)
			my_mlx_pixel_put(&img, i, j, color);
		i++;
		if (i == x)
		{
			i = 0;
			if (j >= 405 && j <= 675)
			{
				if (min_x > 285 && n == 0)
					min_x--;
				if (max_x < 555 && n == 1)
					max_x++;
				if (n == 0)
					n = 1;
				else
					n = 0;
			}
			j++;
		}
	}
}

void	print_pentagon(t_data img, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < x && j < y)
	{
		if (i >= 1365 && i <= 1635 && j >= 405 && j <= 675)
			my_mlx_pixel_put(&img, i, j, color);
		i++;
		if (i == x)
		{
			i = 0;
			j++;
		}
	}
}
