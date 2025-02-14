/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:21:43 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/14 19:29:25 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map	*read_map(char *str, t_fdf *fdf)
{
	int			fd;
	char		*line;
	t_map		*map;
	t_map		*node;
	int			line_count;

	map = (t_map *)malloc(sizeof(t_map));
	map = NULL;
	line_count = 0;
	fd = open(str, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		node = ft_newmap(line, line_count, fdf);
		if (!node)
			return (free(line), NULL);
		free(line);
		ft_mapaddback(&map, node);
		line_count++;
	}
	fdf -> map_height = line_count;
	return (map);
}
