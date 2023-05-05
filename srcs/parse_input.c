/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:26:26 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/05 10:41:10 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "fdf.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static int	char_in_str(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*(str + i))
	{
		if (*(str + i) == c)
			j++;
		i++;
	}
	return (j);
}
/*
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
	points = malloc(sizeof(t_point) * strstr_size(numbers));
	i = 0;
	while (numbers[i])
	{
		if (ft_strchr(numbers[i], ','))
		{
			tmp = ft_split(numbers[i], ',');
			points[i].value = ft_atoi(tmp[0]);
			points[i].color = tmp[1];
			free(tmp[0]);
			free(tmp[1]);
			free(tmp);
		}
		else
			points[i].color = 0;
		points[i].value = ft_atoi(numbers[i]);
		points[i].size = strstr_size(numbers);
		free(numbers[i]);
		i++;
	}
	free(numbers);
	return (points);
}*/

static void	set_points(char **numbers, t_point **p)
{
	t_point	*aux;
	int		i;

	aux = *p;
	i = 0;
	while (numbers[i])
	{
		if (ft_strchr(numbers[i], ','))
			ft_printf("Number contains color info\n");
		aux[i].value = ft_atoi(numbers[i]);
		free(numbers[i++]);
	}
	aux[0].size = i;
}

static t_point	**generate_points(char *input, int size)
{
	t_point	**points;
	t_point	*p;
	char	**split;
	char	**numbers;
	int		i;
	int		j;

	i = 0;
	points = malloc(sizeof(t_point *) * size + 1);
	split = ft_split(input, '\n');
	while (split[i])
	{
		j = 0;
		numbers = ft_split(split[i], ' ');
		while (numbers[j])
			j++;
		p = malloc(sizeof(t_point) * j + 1);
		set_points(numbers, &p);
		points[i] = p;
		free(numbers);
		free(split[i++]);
	}
	points[i] = NULL;
	free(split);
	return (points);
}

t_point **parse(char *file)
{
	int		fd;
	char	*line;
	char	*input;
	char	*aux;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	input = ft_strdup("");
	while (line)
	{
		aux = input;
		input = ft_strjoin(input, line);
		free(aux);
		free(line);
		line = get_next_line(fd);
	}
	free(input);
	free(line);
	close(fd);
	return (generate_points(input, char_in_str(input, '\n')));
}
