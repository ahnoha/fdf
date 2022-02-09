/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:59:53 by nerraou           #+#    #+#             */
/*   Updated: 2022/02/09 16:29:34 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
#define PARSE_H

#include "fdf.h"

typedef struct s_point
{
	int	x;
	int	y;
	int z;
	int color;
}				t_point;

void del_point(void *point);
char	**ft_free(char **str, int size);
t_point ***list_to_array(t_list *list, int h, int w);
int  parse_line(char *line, t_list *list, int y);
t_list *parse_lines(char *file, int *w, int *h);
int  to_decimal(char *str);
void free_points(t_point ***tab, int h);

#endif