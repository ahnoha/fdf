/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:50:57 by nerraou           #+#    #+#             */
/*   Updated: 2022/01/21 16:06:38 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_element
{
	void *content;
	struct s_element *next;
}			t_element;

typedef struct s_list
{
	t_element *head; 
	t_element *tail;
	int		size;
}			t_list;

t_element	*elem_new(void *content);
t_list		*list_new(void);
void		add_front(t_list *list,void *content);
void add_back(t_list *last,void *content);
#endif
