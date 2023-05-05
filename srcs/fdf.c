/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:11:28 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/05 12:56:54 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "fdf.h"
#include "color_defs.h"
#include "mlx.h"
#include <stdlib.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_len + x * (data->bpps / 8));
	*(unsigned int *)dst = color;
}

static void	check_points(t_point **points)
{
	int	i;
	int	j;

	i = 0;
	while (points[i])
	{
		j = 0;
		while (points[i][0].size_col > j)
			ft_printf("%d", points[i][j++].value);
		free(points[i++]);
		ft_printf("\n");
	}
	free(points);
}

void	fdf(char *file)
{
/*	void	*mlx;
	void	*mlx_win;
	t_vars	vars;
	t_data	img;*/
	t_point	**points;

	points = (parse(file));
	check_points(points);
/*	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Fdf");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpps, &img.l_len, &img.endian);
	render_points(points, img);
	check_points(points);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	vars.mlx = mlx;
	vars.win = mlx_win;
	vars.img = img;
	mlx_hook(vars.win, 2, 1l<<0, key_hook, &vars);
	mlx_loop(mlx);*/
}

int	main(int argc, char *argv[])
{
	char	*str;

	if (argc < 2 || argc > 2)
		return (0);
	str = ft_strchr(argv[1], '.');
	if (str)
	{
		if (ft_strncmp(str, "fdf", 3))
			fdf(argv[1]);
	}
	return (0);
}
