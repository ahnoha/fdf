/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:45:45 by nerraou           #+#    #+#             */
/*   Updated: 2022/02/09 17:10:43 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
