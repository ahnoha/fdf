/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:17:03 by nerraou           #+#    #+#             */
/*   Updated: 2022/01/21 12:19:42 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	if (x >= data->width || y >= data->height || x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * 4);
	*(unsigned int*)dst = color;
}
