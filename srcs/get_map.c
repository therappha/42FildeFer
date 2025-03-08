/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:56:09 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/03/08 18:24:45 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	read_map(t_line **map_line, t_fdf *fdf, char *av)
{
	int		fd;
	char	*line;
	t_line	*newline;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		newline = ft_newline(fdf, ft_split(line, ' '));
		if (!newline)
		{
			ft_linefree(map_line);
			free(line);
			line = get_next_line(-1);
			return (-1);
		}
		ft_lineadd_back(map_line, newline);
		free(line);
	}
	close(fd);
	return (0);
}

t_line	*ft_newline(t_fdf *fdf, char **content)
{
	t_line	*newline;

	if (!content)
		return (NULL);
	newline = (t_line *)malloc(sizeof(t_line));
	if (!newline)
		return (NULL);
	if ((*fdf).map_x == -1)
		(*fdf).map_x = ft_linelen(content);
	else if (ft_linelen(content) != (*fdf).map_x)
	{
		free(newline);
		ft_freesplit(content);
		return (NULL);
	}
	newline -> line = content;
	newline -> next = NULL;
	(*fdf).map_y++;
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
