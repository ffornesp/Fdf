/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:41:45 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/09 11:22:38 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define X 0
# define Y 1
# define Z 2

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpps;
	int		l_len;
	int		endian;
}			t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

typedef struct s_point
{
	int		pos[3];
	int		color;
	int		hex_color;
}			t_point;

typedef struct s_map
{
	char	*fdf_file;
	int		limits[3];
	int		len;
	t_point	*points;
}			t_map;

void	load_map(t_map *map, char *fdf_file);

char	*parse_map(int fd);

void	map_init(t_map *map);
void	map_set_size(t_map *map);
void	map_set_points(t_map *map);

int		draw_screen(t_map *map, t_vars *vars, t_data *data);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	line_renderer(t_point *p0, t_point *p1, t_data *img, int scale);

int		key_hook(int keycode, t_vars *vars);

#endif
