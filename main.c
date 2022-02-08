/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:45:45 by nerraou           #+#    #+#             */
/*   Updated: 2022/02/08 19:06:36 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void del_point(void *point)
{
	free(point);
}

void free_points(t_point ***tab, int h)
{
	int i;

	i = 0;
	while (i < h)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

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


void ft_draw(t_data *data, char *file)
{
	int w;
	int h;
	int i;
	int j;
	t_point p1;
	t_point p2;

	i = 0;
	t_list *list = parse_lines(file, &w, &h);
	t_point ***tab = list_to_array(list, h, w);
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			p1 = iso(tab[i][j]->x, tab[i][j]->y, tab[i][j]->z);
			if (j + 1 >= w)
				break ;
			p2 = iso(tab[i][j+1]->x, tab[i][j+1]->y, tab[i][j+1]->z);
			draw_line(data , p1 ,p2 ,tab[i][j]->color);
			if (i + 1 >= h)
				break ;
			p2 = iso(tab[i+1][j]->x, tab[i+1][j]->y, tab[i + 1][j]->z);
			draw_line(data , p1 ,p2 ,tab[i][j]->color);
			j++;
		}
		i++;
	}
	free_points(tab, h);
	list_del(&list, del_point);
}

int main(int ac, char *av[])
{
	t_data data;
	t_mlx  mlx;

	if (ac == 2)
	{
		ft_init(&data, &mlx);
		ft_draw(&data,av[1]);
		mlx_put_image_to_window(mlx.mlx,mlx.mlx_win, data.img, 0,0);
		mlx_key_hook(mlx.mlx_win, key_hook ,&mlx);
	 	mlx_loop(mlx.mlx);
	}
	return 0;
}
