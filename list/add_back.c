/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:45:40 by nerraou           #+#    #+#             */
/*   Updated: 2022/02/14 11:30:08 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	add_back(t_list *list, void *content)
{
	t_element	*elm;

	elm = elem_new(content);
	if (!elm)
		return ;
	if (!list->head)
		list->head = elm;
	if (!list->tail)
		list->tail = elm;
	else
	{
		list->tail->next = elm;
		list->tail = elm;
	}
	list->size++;
}
