/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:11:28 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/01 16:48:59 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "fdf.h"
#include "color_defs.h"
#include "mlx.h"
#include <fcntl.h> // Needed for open

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_len + x * (data->bpps / 8));
	*(unsigned int *)dst = color;
}

void	test_keyhook(void *mlx, void *win)
{
	t_vars	vars;

	vars.mlx = mlx;
	vars.win = win;
	mlx_key_hook(vars.win, key_hook, &vars);
}

void	create_window(void *mlx)
{
	void	*mlx_win;
	t_data	img;
	int		i;
	int		j;

	i = 0;
	j = 0;
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Fdf");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpps, &img.l_len, &img.endian);
	while (i < 1920 && j < 1080)
	{	
		my_mlx_pixel_put(&img, i, j, BLUE);
		i++;
		if (i == 1920)
		{
			i = 0;
			j++;
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	test_keyhook(mlx, mlx_win);
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
			create_window(mlx);
		}
	}
	return (0);
}
