/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:54:59 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/13 22:08:52 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_countwords(const char *s, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i] == c)
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			words++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (words);
}

t_vector *ft_split_points(char *str, int line_count)
{
	int			count_points;
	t_vector	*point_line;
	char 		**elements;
	int			i;

	count_points = ft_countwords(str, ' ');
	point_line = (t_vector *)malloc(sizeof(t_vector) * count_points);
	elements = ft_split(str, ' ');
	i = 0;
	while (i < count_points)
	{
		point_line[i].x = i;
		point_line[i].y = ft_atoi(elements[i]);
		point_line[i].z = line_count;
		point_line[i].color = get_color(elements[i]);
		i++;
	}
	ft_freesplit(elements, count_points);
	return (point_line);
}

t_map	*ft_newmap(char *line, int line_count)
{
	t_map *map = (t_map *)malloc(sizeof(t_map));

	map -> line = ft_split_points(line, line_count);
	map -> next = NULL;
	map -> line_count = line_count;
	return (map);
}
void	ft_mapaddback(t_map **map, t_map *node)
{
	t_map *head;

	head = *map;
	if (!head)
	{
		*map = node;
		return ;
	}
	while (head -> next)
	{
		head = head -> next;
	}
	head -> next = node;
}

void	ft_freemap(t_map **map)
{
	t_map	*head;
	t_map	*temp;

	head = *map;
	while (head)
	{
		free(head -> line);
		temp = head -> next;
		free (head);
		head = temp;
	}
}
