/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:35:32 by nerraou           #+#    #+#             */
/*   Updated: 2022/02/15 18:13:48 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_scale(t_data *d, int w, int h)
{
	int	s1;
	int	s2;

	s1 = (sqrt(2.0) / 2.0) * (d->width / w);
	s2 = (sqrt(2.0) / 2.0) * (d->height / h);
	if (s1 <= s2)
		d->s = s1 - 1;
	else if (s1 < 1 || s2 < 1)
		d->s = 1;
	else if (s1 >= s2)
		d->s = s2 - 1;
}

void	draw_lines(t_point ***t, t_data *d, int w, int h)
{
	int			i;
	int			j;
	t_point		p1;
	t_point		p2;
	
	i = -1;
	set_scale(d, w, h);
	while (++i < h)
	{
		j = -1;
		while (++j < w)
		{
			p1 = iso(t[i][j]->x, t[i][j]->y, t[i][j]->z, d->s);
			if (j < w -1)
			{
				p2 = iso(t[i][j + 1]->x, t[i][j + 1]->y, t[i][j + 1]->z, d->s);
				draw_line(d, p1, p2, t[i][j]->color);
			}
			if (i < h -1)
			{
				p2 = iso(t[i + 1][j]->x, t[i + 1][j]->y, t[i + 1][j]->z, d->s);
				draw_line(d, p1, p2, t[i][j]->color);
			}
			
		}
	}
}
