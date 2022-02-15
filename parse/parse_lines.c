/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:05:49 by nerraou           #+#    #+#             */
/*   Updated: 2022/02/15 16:09:28 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	t_list	*dummy_del(t_list **list)
{
	list_del(list, del_point);
	return (NULL);
}

t_list	*parse_lines(char *file, int *w, int *h)
{
	int		y;
	int		fd;
	int		prev_w;
	char	*line;
	t_list	*list;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	list = list_new();
	if (!list)
		return (NULL);
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		//TODO try to make this a function 
		*w = parse_line(line, list, y);
		if (y == 0)
			prev_w = *w;
		free(line);
		if (*w == -1 || prev_w != *w)
			return (dummy_del(&list));
		line = get_next_line(fd);
		y++;
	}
	*h = y;
	return (list);
}
