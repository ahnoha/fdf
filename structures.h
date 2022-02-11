/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:44:07 by nerraou           #+#    #+#             */
/*   Updated: 2022/02/11 17:47:42 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STUCTURES_H
#define STUCTURES_H

#include "fdf.h"

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

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

typedef struct s_point
{
	int	x;
	int	y;
	int z;
	int color;
}				t_point;

#endif
