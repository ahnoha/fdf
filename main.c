/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:45:45 by nerraou           #+#    #+#             */
/*   Updated: 2022/01/17 17:43:17 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	if (x > 600 || y > 400 || x < 0|| y < 0) return ;
	dst = data->addr + (y * data->line_length + x * 4);
	*(unsigned int*)dst = color;
}
// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	(void)color;
// 	(void)x;
// 	(void)y;
// 	int i = 600 * 4 * y + x * 4;
// 	data->addr[i] = (char)255;
// 	data->addr[i + 1] = (char)255;
// 	data->addr[i + 2] = (char)255;
// 	// while (i < 600 * 4 * 40)
// 	// {
// 	// 	i++;
// 	// 	if (i % 4 == 3)continue;
// 	// 	data->addr[i] = (char)255;
// 	// }
// }

// int f(int x)
// {
// 	return 2 * x;
// // 	y = i;
// // 	x += (i % 2) ? 1: 2;
// // }

int main()
{
	t_data img;
	void	*mlx;
	void	*mlx_win;
	int		i;
	int x, y;

	x= y = 0;
	i = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 400, "FDF");
	img.img = mlx_new_image(mlx, 600, 400);
	printf("soso : %d\n", img.line_length);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	printf("s : %d\n", img.line_length);

	while (i < 600 * 400)
	{
		if (i % 600 < 10)
		{
			x = i % 600;
			y = (int)(i / 400);
			
			my_mlx_pixel_put(&img, x, y, 0xFF0000);
		}
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0,0);
	mlx_loop(mlx);
	return 0;
}
