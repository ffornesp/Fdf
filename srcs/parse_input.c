/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:26:26 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/15 16:31:14 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "fdf.h"
#include <stdlib.h>

char	*parse_map(int fd)
{
	char	*line;
	char	*input;
	char	*aux;

	input = ft_strdup("");
	line = get_next_line(fd);
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
