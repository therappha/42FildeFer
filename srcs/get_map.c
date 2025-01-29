/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:56:09 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/28 17:48:46 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void read_map(t_fdf **fdf, t_line **map_line, char *av)
{
	int		fd;
	char	*line;
	t_line *newline;

	fd = open(av, O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		newline = ft_newline(ft_split(line, ' '));
		ft_lineadd_back(map_line, newline);
		free(line);
	}
}

t_line *ft_newline(char **content)
{
	t_line	*newline;

	newline = (t_line *)malloc(sizeof(t_line));
	if (!newline)
		return (NULL);
	newline -> line = content;
	newline -> next = NULL;
	return (newline);
}

t_line	*ft_linelast(t_line *line)
{
	if (!line)
		return (NULL);
	while (line -> next)
		line = line -> next;
	return (line);
}

void	ft_lineadd_back(t_line **line, t_line *new)
{
	t_line	*temp;

	if (!new)
		return ;
	if (!*line)
	{
		*line = new;
		return ;
	}
	temp = ft_linelast(*line);
	temp -> next = new;
}
