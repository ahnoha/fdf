/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:26:01 by nerraou           #+#    #+#             */
/*   Updated: 2022/02/14 13:20:25 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init(t_data *data, t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	data->width = 800;
	data->height = 660;
	mlx->mlx_win = mlx_new_window(mlx->mlx, data->width, data->height, "FDF");
	data->img = mlx_new_image(mlx->mlx, data->width, data->height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
}
