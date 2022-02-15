/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:04:58 by nerraou           #+#    #+#             */
/*   Updated: 2022/02/15 13:31:54 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	sub_err(int *err, int *x, int dy, int sx)
{
	*err -= dy;
	*x += sx;
}

static	void	add_err(int *err, int *y, int dx, int sy)
{
	*err += dx;
	*y += sy;
}

static	void	set_var(t_point *d, t_point *s, t_point p0, t_point p1)
{
	d->x = abs(p0.x - p1.x);
	d->y = abs(p0.y - p1.y);
	if (p0.x < p1.x)
		s->x = 1;
	else
		s->x = -1;
	if (p0.y < p1.y)
		s->y = 1;
	else
		s->y = -1;
}

void	draw_line(t_data *img, t_point p0, t_point p1, int color)
{
	t_point		d;
	t_point		s;
	int			err;

	set_var(&d, &s, p0, p1);
	err = d.x - d.y;
	while (1)
	{
		ft_mlx_pixel_put(img, p0.x + img->width / 2, \
			p0.y + img->height / 4, color);
		if ((2 * err) + d.y >= 0)
		{
			if (p0.x == p1.x)
				break ;
			sub_err(&err, &p0.x, d.y, s.x);
		}
		if ((2 * err) - d.y <= 0)
		{
			if (p0.y == p1.y)
				break ;
			add_err(&err, &p0.y, d.x, s.y);
		}
	}
}
