/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:59:53 by nerraou           #+#    #+#             */
/*   Updated: 2022/02/14 13:11:50 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "fdf.h"

void	del_point(void *point);
void	free_points(t_point ***tab, int h);

char	**ft_free(char **str, int size);

t_point	***list_to_array(t_list *list, int h, int w);
t_list	*parse_lines(char *file, int *w, int *h);

int		parse_line(char *line, t_list *list, int y);
int		to_decimal(char *str);
int		ft_atoi(const char *str);

#endif