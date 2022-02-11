/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:29:02 by nerraou           #+#    #+#             */
/*   Updated: 2022/02/11 17:35:19 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
#define DRAW_H

#include "fdf.h"

void draw_line(t_data *img, t_point p0, t_point p1, int color);
void draw_lines(t_point ***tab, t_data *data, int w, int h);
void ft_draw(t_data *data, char *file);
#endif