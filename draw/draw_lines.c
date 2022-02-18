/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:35:32 by nerraou           #+#    #+#             */
/*   Updated: 2022/02/18 11:01:35 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	get_left_shift(t_point ***t, t_data *d, int w, int h)
{
	t_point	b;
	t_point	c;
	float	diff;

	b = iso(t[0][w - 1]->x, t[0][w - 1]->y, t[0][w - 1]->z, 1);
	c = iso(t[h - 1][0]->x, t[h - 1][0]->y, t[h - 1][0]->z, 1);
	diff = ((b.x - c.x) * d->s) / 2.0f;
	return ((-1.0f * c.x * d->s) + (d->width / 2.0f) - diff);
}

void	draw_lines(t_point ***t, t_data *d, int w, int h)
{
	int			i;
	int			j;
	t_point		p1;
	t_point		p2;

	i = -1;
	while (++i < h)
	{
		j = -1;
		while (++j < w)
		{
			p1 = iso(t[i][j]->x, t[i][j]->y, t[i][j]->z, d->s);
			p1.color = t[i][j]->color;
			if (j < w -1)
			{
				p2 = iso(t[i][j + 1]->x, t[i][j + 1]->y, t[i][j + 1]->z, d->s);
				draw_line(d, p1, p2, get_left_shift(t, d, w, h));
			}
			if (i < h -1)
			{
				p2 = iso(t[i + 1][j]->x, t[i + 1][j]->y, t[i + 1][j]->z, d->s);
				draw_line(d, p1, p2, get_left_shift(t, d, w, h));
			}
		}
	}
}
