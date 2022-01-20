/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:45:45 by nerraou           #+#    #+#             */
/*   Updated: 2022/01/20 16:43:13 by nerraou          ###   ########.fr       */
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
		ft_mlx_pixel_put(img, p0.x, p0.y, color);
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


int main()
{
	t_point p1;
	t_point p2;
	t_point p3;
	t_data data;
	t_mlx  mlx;
	int color;
	
	color = create_trgb(50,255,100,20);
	p1.x = 50;
	p1.y = 50;
	
	p2.x = 239;
	p2.y = 159;

	p3.x = 159;
	p3.y = 50;
	ft_init(&data, &mlx);
	printf("%p",mlx.mlx);
 	draw_line(&data, p2, p1 ,color);
	draw_line(&data, p2, p3 ,color);
	draw_line(&data, p1, p3 ,color);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, data.img, 0,0);
	mlx_loop(mlx.mlx);
	return 0;
}
