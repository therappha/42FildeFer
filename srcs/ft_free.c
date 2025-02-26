/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:39:30 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/26 19:03:54 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_freesplit(char **str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		free (str[i]);
		i++;
	}
	free(str);
}

void	ft_linefree(t_line **line)
{
	t_line	*temp;

	while (*line)
	{
		temp = (*line)-> next;
		ft_freesplit((*line) -> line);
		free(*line);
		*line = temp;
	}
}

int	input_handler(int keysym, t_fdf *fdf)
{
	if (keysym == XK_Escape)
		free_displays(fdf);
	return (0);
}
