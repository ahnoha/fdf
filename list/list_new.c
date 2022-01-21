/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:03:21 by nerraou           #+#    #+#             */
/*   Updated: 2022/01/21 16:22:34 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*list_new(void)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->head = NULL;
	new_list->tail = NULL;
	new_list->size = 0;
	return (new_list);
}
