/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:42:03 by nerraou           #+#    #+#             */
/*   Updated: 2022/02/14 11:46:34 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	***list_to_array(t_list *list, int h, int w)
{
	int			i;
	int			j;
	t_point		***tab;
	t_element	*cur;

	cur = list->head;
	tab = (t_point ***)malloc(sizeof(t_point **) * h);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < h)
	{
		tab[i] = (t_point **)malloc(sizeof(t_point *) * w);
		if (!tab)
			return (NULL);
		j = 0;
		while (j < w)
		{
			tab[i][j] = (t_point *)cur->content;
			cur = cur->next;
			j++;
		}
		i++;
	}
	return (tab);
}
