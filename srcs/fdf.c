/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:11:28 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/04 18:48:14 by ffornes-         ###   ########.fr       */
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
/*
void	check_points(char *file)
{
	t_point	**points;
	t_point	*tmp;
	int		i;
	int		j;

	points = malloc(sizeof(t_point *));
	if (!parse(file, points))
		ft_printf("Parse error\n");
	i = 0;
	while (points[i])
	{
		j = 0;
		tmp = points[i];
		while (j < points[0][0].size)
		{
			ft_printf("%d ", points[i][j].value);
			if (points[i][j].color != 0)
				ft_printf("%s ", points[i][j].color);
			j++;
		}
		ft_printf("\n");
		free(points[i]);
		i++;
	}
	free(points);
}*/

void	fdf(void *mlx, char *file)
{
//	void	*mlx_win;
//	t_vars	vars;
//	t_data	img;
	
	//check_points(file);
	free(parse(file));
	mlx = NULL;
	return ;
	/*
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Fdf");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpps, &img.l_len, &img.endian);
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
	void	*mlx;

	if (argc < 2 || argc > 2)
		return (0);
	str = ft_strchr(argv[1], '.');
	if (str)
	{
		if (ft_strncmp(str, "fdf", 3))
		{
			mlx = NULL;
			//mlx = mlx_init();
			fdf(mlx, argv[1]);
		}
	}
	return (0);
}
