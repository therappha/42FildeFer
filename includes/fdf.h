/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:34:13 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/28 23:23:25 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libs/libft/includes/libft.h"
# include "../libs/mlx/mlx.h"
# include "../libs/mlx/mlx_int.h"
# include <strings.h>
# include <limits.h>
# include <math.h>


typedef struct	s_point
{
	int	x;
	int	y;
	int	color;
}	t_point;

typedef struct	s_line
{
	char **line;
	struct s_line *next;
}	t_line;

typedef	struct	s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		screen_x;
	int		screen_y;
}	t_fdf;

void	drawline(t_fdf **fdf, t_point start, t_point dest);
void	drawmap(t_fdf **fdf, t_line **line, int distance);
void	read_map(t_fdf **fdf, t_line **map_line, char *av);
int		free_displays(t_fdf **fdf);

//math convertions
t_point	cartesian_to_iso(t_point cartesian, char *str_height, int distance, int color);
int	ft_atoi_16(char *str);

//struct utils
t_line	*ft_newline(char **content);
void	ft_lineadd_back(t_line **lst, t_line *new);

# define T(a) ((a) >> 24) & 0xFF
# define R(a) ((a) >> 16) & 0xFF
# define G(a) ((a) >> 8) & 0xFF
# define B(a) (a) & 0xFF
# define RGB(r, g, b) ((0xFF << 24) | ((r) << 16) | ((g) << 8) | (b))

# endif
