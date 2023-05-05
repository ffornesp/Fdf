/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:41:45 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/05 12:56:10 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

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
	t_data	img;
}			t_vars;

typedef struct s_point
{
	int		value;
	char	*color;
	int		size_col;
}			t_point;

t_point			**parse(char *file);

void			line_renderer(int *p0, int *p1, t_data img);

void			render_points(t_point **points, t_data img);

void			print_pentagon(t_data img, int x, int y, int color);
void			print_square(t_data img, int x, int y, int color);
void			print_triangle(t_data img, int x, int y, int color);
void			image_color(t_data *img, int x, int y, int color);

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

int				key_hook(int keycode, t_vars *vars);

// LiNe ToO lOnG
int				c_color(unsigned char t, unsigned char r, unsigned char g, unsigned char b);
unsigned char	get_t(int trgb);
unsigned char	get_r(int trgb);
unsigned char	get_g(int trgb);
unsigned char	get_b(int trgb);

#endif
