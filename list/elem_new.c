/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:58:59 by nerraou           #+#    #+#             */
/*   Updated: 2022/01/21 16:09:18 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_element	*elem_new(void *content)
{
	t_element	*new_elm;
	
	new_elm = (t_element *)malloc(sizeof(t_element));
	if (!new_elm)
		return (NULL);
	new_elm->content = content;
	new_elm->next = NULL;
	return (new_elm);
}
