/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_front.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:07:30 by nerraou           #+#    #+#             */
/*   Updated: 2022/02/14 11:34:39 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	add_front(t_list *list, void *content)
{
	t_element	*elm;

	elm = elem_new(content);
	if (!elm)
		return ;
	if (!list->tail)
		list->tail = elm;
	elm->next = list->head;
	list->head = elm;
	list->size++;
}
