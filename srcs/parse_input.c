/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:26:26 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/04 11:35:23 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

static int	strstr_size(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static t_point	*save_points(char *line)
{
	t_point	*points;
	char	**numbers;
	char	**tmp;
	int		i;

	numbers = ft_split(line, ' ');
	points = malloc(sizeof(t_point) * strstr_size(numbers) + 1);
	i = 0;
	while (numbers[i])
	{
		if (ft_strchr(numbers[i], ','))
		{
			tmp = ft_split(numbers[i], ',');
			points[i]->value = ft_atoi(tmp[0]);
			points[i]->color = ft_atoi(tmp[1]);
			free(tmp[0]);
			free(tmp[1]);
			free(tmp);
		}
		else
			points[i]->value = ft_atoi(numbers[i]);
		free(numbers[i++]);
	}
	return (points);
}

void	parse(char	*file)
{
	int		fd;
	char	*line;
	t_point	**points;
	int		i;

	fd = open(file, 0_RDONLY);
	if (fd < 0)
		return ;
	points = malloc(sizeof(t_point));
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		points[i++] = save_points(line);
		free(line);
		line = get_next_line(fd);
	}
	if (i == 0 && !line)
		return ;
}
