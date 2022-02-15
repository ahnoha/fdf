/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:36:31 by nerraou           #+#    #+#             */
/*   Updated: 2022/02/15 21:05:52 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

static void	set_scale(t_data *d, int w, int h)
{
	int	s1;
	int	s2;

	s1 = 0.666 * ((float)d->width / (float)w / 1.5);
	s2 =  0.666 * ((float)d->height / (float)h );
	if (s1 <= s2)
		d->s = s1;
	if (s1 < 1 || s2 < 1)
		d->s = 1;
	else if (s1 >= s2)
		d->s = s2;
}

void	get_new_dimension(t_point ***tab, t_data *data, int w, int h)
{
	int new_w;
	int new_h;
	
	t_point a;
	t_point b;
	t_point c;
	t_point d;

	a = iso(tab[0][0]->x,tab[0][0]->y,tab[0][0]->z,1);
	b = iso(tab[0][w - 1]->x,tab[0][w - 1]->y,tab[0][w - 1]->z, 1);
	c = iso(tab[h - 1][0]->x,tab[h - 1][0]->y,tab[h - 1][0]->z, 1);
	d = iso(tab[h - 1][w - 1]->x,tab[h - 1][w - 1]->y,tab[h - 1][w - 1]->z, 1);
	
	printf("[ay]%d [ax]%d\n",a.y,a.x);
	printf("[by]%d [bx]%d\n",b.y,b.x);
	printf("[cy]%d [cx]%d\n",c.y,c.x);
	printf("[dy]%d [dy]%d\n",d.y,d.x);
	
	int minX = min(a.x,min(b.x,min(c.x,d.x)));
	int maxX = max(a.x,max(b.x,max(c.x,d.x)));
	int minY = min(a.y,min(b.y,min(c.y,d.y)));
	int maxY = max(a.y,max(b.y,max(c.y,d.y)));
	
	new_w = abs(maxX) + abs(minX);
	new_h = abs(maxY) + abs(minY);
	
	set_scale(data, maxX, new_h);
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
