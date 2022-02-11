/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:36:31 by nerraou           #+#    #+#             */
/*   Updated: 2022/02/11 17:36:49 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_draw(t_data *data, char *file)
{
	int w;
	int h;
	
	t_list *list = parse_lines(file, &w, &h);
	t_point ***tab = list_to_array(list, h, w);
	draw_lines(tab,data,w,h);
	free_points(tab, h);
	list_del(&list, del_point);
}