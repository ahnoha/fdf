/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:35:32 by nerraou           #+#    #+#             */
/*   Updated: 2022/02/11 18:55:17 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_lines(t_point ***tab, t_data *data, int w, int h)
{
	int i;
	int j;
	t_point p1;
	t_point p2;
	
	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			p1 = iso(tab[i][j]->x, tab[i][j]->y, tab[i][j]->z);
			// if (j + 1 >= w)
			// 	break ;
			if(j < w -1)
			{
				p2 = iso(tab[i][j+1]->x, tab[i][j+1]->y, tab[i][j+1]->z);
				draw_line(data , p1 ,p2 ,tab[i][j]->color);
			}
			
			// if (i + 1 >= h)
			// 	break ;
			if (i < h -1)
			{
				p2 = iso(tab[i+1][j]->x, tab[i+1][j]->y, tab[i + 1][j]->z);
				draw_line(data , p1 ,p2 ,tab[i][j]->color);
			}
			
			j++;
		}
		i++;
	}
}