/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:05:49 by nerraou           #+#    #+#             */
/*   Updated: 2022/02/17 16:34:28 by nerraou          ###   ########.fr       */
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
	*h = 0;
	while (line)
	{
		*w = parse_line(line, list, *h);
		if (*h == 0)
			prev_w = *w;
		free(line);
		if (*w == -1 || prev_w != *w)
			return (dummy_del(&list));
		line = get_next_line(fd);
		(*h)++;
	}
	return (list);
}
