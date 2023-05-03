/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:45:06 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/03 10:40:02 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "color_defs.h"
#include "mlx.h"
#include <stdlib.h>

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(1);
	}
	else if (keycode == 5)
		print_square(vars->img, 1920, 1080, GREEN);
	else if (keycode == 11)
		print_square(vars->img, 1920, 1080, BLUE);
	else if (keycode == 15)
		print_square(vars->img, 1920, 1080, RED);
	else
		return (0);
	if (keycode >= 5 && keycode <= 15)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (1);
}
