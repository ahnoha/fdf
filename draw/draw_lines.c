/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:35:32 by nerraou           #+#    #+#             */
/*   Updated: 2022/02/15 19:06:19 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



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
