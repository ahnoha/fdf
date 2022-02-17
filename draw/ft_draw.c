/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:36:31 by nerraou           #+#    #+#             */
/*   Updated: 2022/02/17 18:45:42 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_scale(t_data *d, float w, float h)
{
	float	s1;
	float	s2;

	s1 = 0.9 * (d->width / w);
	s2 = 0.9 * (d->height / h);
	if (s1 < s2)
		d->s = s1;
	else if (s1 > s2)
		d->s = s2;
}

void	get_new_dimension(t_point ***t, t_data *data, int w, int h)
{
	float	new_w;
	float	new_h;
	t_point	p[4];
	float	values[4];

	p[0] = iso(t[0][0]->x, t[0][0]->y, t[0][0]->z, 1);
	p[1] = iso(t[0][w - 1]->x, t[0][w - 1]->y, t[0][w - 1]->z, 1);
	p[2] = iso(t[h - 1][0]->x, t[h - 1][0]->y, t[h - 1][0]->z, 1);
	p[3] = iso(t[h - 1][w - 1]->x, t[h - 1][w - 1]->y, t[h - 1][w - 1]->z, 1);
	values[0] = fminf(p[0].x, fminf(p[1].x, fminf(p[2].x, p[3].x)));
	values[1] = fmaxf(p[0].x, fmaxf(p[1].x, fmaxf(p[2].x, p[3].x)));
	values[2] = fminf(p[0].y, fminf(p[1].y, fminf(p[2].y, p[3].y)));
	values[3] = fmaxf(p[0].y, fmaxf(p[1].y, fmaxf(p[2].y, p[3].y)));
	new_w = values[1] + fabsf(values[0]);
	new_h = values[3] + fabsf(values[2]);
	set_scale(data, new_w, new_h);
}

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
	get_new_dimension(tab, data, w, h);
	draw_lines(tab, data, w, h);
	free_points(tab, h);
	list_del(&list, del_point);
}
