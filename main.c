/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:45:45 by nerraou           #+#    #+#             */
/*   Updated: 2022/02/11 17:36:54 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


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
