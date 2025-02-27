/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:01:46 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/27 19:51:44 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_linelen(char **line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

int	get_scale(t_fdf *fdf)
{
	int	scale_x;

	scale_x = 500 / (*fdf).map_x;
	if (scale_x == 0)
		return (1);
	if ((*fdf).map_y <= (*fdf).map_x / 2)
		return (scale_x * 1.5);
	return (scale_x);
}

