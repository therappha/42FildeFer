/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:07:28 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/26 22:01:53 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	cart_to_iso(t_point cartesian, char *s_height, int distance, int color)
{
	t_point	isometric;
	int		height;

	if (distance <= 0)
		distance = 1;
	height = (ft_atoi(s_height)) * distance;
	cartesian.x *= distance;
	cartesian.y *= distance;
	isometric.x = (cartesian.x + cartesian.y);
	isometric.y = (cartesian.y - cartesian.x) / 2 - height / 2;
	isometric.color = color;
	return (isometric);
}

static int	char_value(char c)
{
	int		value;
	char	*baselow;
	char	*baseup;

	baseup = "0123456789ABCDEF";
	baselow = "0123456789abcdef";
	value = 0;
	while (c != baselow[value] && c != baseup[value])
		value++;
	if (c == baselow[value] || c == baseup[value])
		return (value);
	else
		return (-1);
}

int	ft_atoi_16(char *str)
{
	long	num;
	int		signal;

	num = 0;
	signal = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signal *= -1;
		str++;
	}
	while (*str && char_value(*str) != -1)
	{
		num = num * 16 + char_value(*str);
		str++;
	}
	num *= signal;
	return ((int)num);
}

void	ft_pixelput(t_image *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > SCREEN_SIZE_X || y < 0 || y > SCREEN_SIZE_Y)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
