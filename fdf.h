/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:43:33 by nerraou           #+#    #+#             */
/*   Updated: 2022/01/18 19:23:19 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
#define FDF_H

#include <math.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int 	line_length;
	int		endian;
	int		width;
	int		height;
}					t_data;

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void 	ft_init(t_data *data, t_mlx *mlx);
int		create_trgb(int t, int r, int g, int b);

#endif
