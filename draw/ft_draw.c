/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:36:31 by nerraou           #+#    #+#             */
/*   Updated: 2022/02/14 18:59:48 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw(t_data *data, char *file)
{
	int			w;
	int			h;
	t_list		*list;
	t_point		***tab;

	list = parse_lines(file, &w, &h);
	data->s = 1;
	if (!list)
		exit(1);
	tab = list_to_array(list, h, w);
	if (!tab)
	{
		list_del(&list, del_point);
		exit(1);
	}
	draw_lines(tab, data, w, h);
	free_points(tab, h);
	list_del(&list, del_point);
}
