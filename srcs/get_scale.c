/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:01:46 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/27 19:26:08 by rafaelfe         ###   ########.fr       */
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
	int	scale_y;

	scale_x = 500 / (*fdf).map_x;
	scale_y = 400 / (*fdf).map_y;
	if (scale_x == 0 && scale_y == 0)
		return (1);
	if (scale_x > scale_y)
		return (scale_x);
	else
		return (scale_y);
}
