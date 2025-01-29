/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:07:28 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/28 23:24:19 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// t_point	cartesian_to_iso(t_point cartesian, char *str_height, int distance, int color)
// {
// 	t_point	isometric;
// 	int		height;

// 	height = (ft_atoi(str_height)) * distance;
// 	cartesian.x *= distance;
// 	cartesian.y *= distance;
// 	isometric.x = (cartesian.x - cartesian.y);
// 	isometric.y = ((cartesian.x + cartesian.y) / 2) - height;
// 	isometric.color = color;
// 	return (isometric);
// }

t_point	cartesian_to_iso(t_point cartesian, char *str_height, int distance, int color)
{
	t_point	isometric;
	int		height;

	height = (ft_atoi(str_height)) * distance;
	cartesian.x *= distance;
	cartesian.y *= distance;
	isometric.x = (cartesian.x + cartesian.y); // Adjusted for left rotation
	isometric.y = (cartesian.y - cartesian.x) / 2 - height / 2; // Adjusted for left rotation
	isometric.color = color;
	return (isometric);
}

static int	char_value(char c)
{
	int	value;
	char *baselow = "0123456789abcdef";
	char *baseup = "0123456789ABCDEF";

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
