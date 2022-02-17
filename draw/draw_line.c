/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:04:58 by nerraou           #+#    #+#             */
/*   Updated: 2022/02/17 18:13:31 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	sub_err(float *err, float *x, float dy, float sx)
{
	*err -= dy;
	*x += sx;
}

static	void	add_err(float *err, float *y, float dx, float sy)
{
	*err += dx;
	*y += sy;
}

static	void	set_var(t_point *d, t_point *s, t_point p0, t_point p1)
{
	d->x = fabsf(p0.x - p1.x);
	d->y = fabsf(p0.y - p1.y);
	if (p0.x < p1.x)
		s->x = 1;
	else
		s->x = -1;
	if (p0.y < p1.y)
		s->y = 1;
	else
		s->y = -1;
}

void	draw_line(t_data *img, t_point p0, t_point p1, float left)
{
	t_point		d;
	t_point		s;
	float		err;

	set_var(&d, &s, p0, p1);
	err = d.x - d.y;
	while (1)
	{
		ft_mlx_pixel_put(img, p0.x + left, p0.y + (img->height / 5.0f), \
		p0.color);
		if ((2.0f * err) + d.y >= 0.0f)
		{
			if (p0.x - p1.x >= -0.0f && p0.x - p1.x <= 1.0f)
				break ;
			sub_err(&err, &p0.x, d.y, s.x);
		}
		if ((2 * err) - d.y <= 0.0f)
		{
			if (p0.y - p1.y >= -0.0f && p0.y - p1.y <= 1.0f)
				break ;
			add_err(&err, &p0.y, d.x, s.y);
		}
	}
}
