/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:54:42 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/02 12:43:24 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "fdf.h"
#include "mlx.h"

void	image_color(t_data *img, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < x && j < y)
	{
		my_mlx_pixel_put(img, i, j, color);
		i++;
		if (i == x)
		{
			i = 0;
			j++;
		}
	}
}
