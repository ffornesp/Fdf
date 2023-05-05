/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:26:26 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/05 15:49:23 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "fdf.h"
#include <stdlib.h>

/*
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

static void	set_points(char **numbers, t_point **p)
{
	t_point	*aux;
	int		i;
	int		j;

	aux = *p;
	i = 0;
	j = 0;
	while (numbers[i])
	{
		if (ft_strchr(numbers[i], ','))
			ft_printf("Number contains color info\n");
		aux[i].value = ft_atoi(numbers[i]);
		free(numbers[i++]);
	}
	while (j < i)
		aux[j++].size_col = i;
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
	free(input);
	free(split);
	return (points);
}*/

char	*parse_map(int fd)
{
	char	*line;
	char	*input;
	char	*aux;

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
	free(line);
	return (input);
}
