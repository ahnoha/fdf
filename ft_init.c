/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:26:01 by nerraou           #+#    #+#             */
/*   Updated: 2022/01/18 17:54:41 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_init(t_data *data, t_mlx *mlx)
{

	mlx->mlx = mlx_init();
	data->width = 640;
	data->height = 360;
	mlx->mlx_win = mlx_new_window(mlx->mlx, data->width, data->height, "FDF");
	data->img = mlx_new_image(mlx->mlx, data->width, data->height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
}
