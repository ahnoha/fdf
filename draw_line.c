/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:04:58 by nerraou           #+#    #+#             */
/*   Updated: 2022/02/09 17:05:37 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_line(t_data *img, t_point p0, t_point p1, int color)
{
	int dx = abs(p0.x - p1.x);
	int dy = abs(p0.y - p1.y);
	int sx = (p0.x < p1.x) ? 1 : -1;
	int sy = (p0.y < p1.y) ? 1 : -1;
	int err = dx - dy;
	int e2;

	while (1)
	{
		ft_mlx_pixel_put(img, p0.x  + img->width / 2 , p0.y + img->height / 4, color);
		e2 = 2 * err;
		if (e2 + dy >= 0)
		{
			if (p0.x == p1.x)
				break;
			err -= dy;
			p0.x += sx;
		}
		if (e2 - dy <= 0)
		{
			if (p0.y == p1.y)
				break;
			err += dx;
			p0.y += sy;
		}
	}
}

