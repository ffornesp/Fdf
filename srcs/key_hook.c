/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:45:06 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/17 14:43:14 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "fdf.h"
#include "keycode_defs.h"
#include "mlx.h"
#include <stdlib.h>

int	key_hook(int keycode, t_vars *vars)
{
	ft_printf("Keycode: %d\n", keycode);
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(1);
	}
	else
		return (0);
	return (1);
}

int	finish_execution(void)
{
	exit(1);
	return (0);
}
