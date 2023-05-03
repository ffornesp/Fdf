/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:11:28 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/03 15:03:58 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "fdf.h"
#include "color_defs.h"
#include "mlx.h"
#include <fcntl.h> // Needed for open
#include <stdlib.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_len + x * (data->bpps / 8));
	*(unsigned int *)dst = color;
}

void	fdf(void *mlx, int x, int y)
{
	void	*mlx_win;
	t_vars	vars;
	t_data	img;

	mlx_win = mlx_new_window(mlx, x, y, "Fdf");
	img.img = mlx_new_image(mlx, x, y);
	img.addr = mlx_get_data_addr(img.img, &img.bpps, &img.l_len, &img.endian);
	// Change pixel
	int	*p0 = malloc(sizeof(int) * 2);
	int *p1 = malloc(sizeof(int) * 2);
	p0[0] = 100;
	p0[1] = 200;
	p1[0] = 105;
	p1[1] = 205;
	line_renderer(p0, p1, img);
	free(p0);
	free(p1);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	vars.mlx = mlx;
	vars.win = mlx_win;
	vars.img = img;
	mlx_hook(vars.win, 2, 1l<<0, key_hook, &vars);
	mlx_loop(mlx);
}

int	main(int argc, char *argv[])
{
	char	*str;
	void	*mlx;

	if (argc < 2 || argc > 2)
		return (0);
	str = ft_strchr(argv[1], '.');
	if (str)
	{
		if (ft_strncmp(str, "fdf", 3))
		{
			mlx = mlx_init();
			fdf(mlx, 1920, 1080);
		}
	}
	return (0);
}
