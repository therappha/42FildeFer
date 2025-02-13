/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:54:59 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/13 21:20:07 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map	*ft_newmap(t_line *line, int line_count)
{
	t_map *map = (t_map *)malloc(sizeof(t_map));

	map -> line = line;
	map -> next = NULL;
	map -> line_count = line_count;
	return (map);
}
void	ft_mapaddback(t_map **map, t_map *node)
{
	t_map *head;

	head = *map;
	if (!head)
		*map = node;
	else
	{
		while (head -> next)
		{
			head = head -> next;
		}
		head -> next = node;
	}
}
