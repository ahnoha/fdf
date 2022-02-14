/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:46:57 by nerraou           #+#    #+#             */
/*   Updated: 2022/02/14 12:04:49 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	get_color(char *points, t_point *p)
{
	int	i;

	i = ft_indexof(points, 'x');
	if (i > -1)
		p->color = to_decimal(points + i + 1);
	else
		p->color = 0xffffff;
}

int	parse_line(char *line, t_list *list, int y)
{
	char	**points;
	int		x;
	t_point	*p;

	x = 0;
	points = ft_split(line, ' ');
	if (!points)
		return (-1);
	while (points[x])
	{
		p = (t_point *)malloc(sizeof(t_point));
		if (!p)
		{
			ft_free(points, x);
			return (-1);
		}		
		p->x = x;
		p->y = y;
		p->z = ft_atoi(points[x]);
		get_color(points[x], p);
		add_back(list, p);
		x++;
	}
	ft_free(points, x);
	return (x);
}
