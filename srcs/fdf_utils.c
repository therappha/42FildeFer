/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:07:28 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/12 21:00:14 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

int	get_color(char *str)
{
	int	color;
	char *colorstr;
	colorstr = NULL;
	colorstr = ft_strnstr(str, "0x", ft_strlen(str));
	if (colorstr)
		{
			color = ft_atoi_16(colorstr + 2);
		}
	else
		color = (0xFFFFFF);
	return (color);
}

void	ft_pixelput(t_point point1, t_point point2, t_fdf *fdf)
{
	
}
