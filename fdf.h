/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:43:33 by nerraou           #+#    #+#             */
/*   Updated: 2022/02/14 13:15:03 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

# include "get_next_line.h"
# include "split.h"
# include "list.h"
# include "structures.h"
# include "parse.h"
# include "draw.h"

char	**ft_split(char const *s, char c);

char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_init(t_data *data, t_mlx *mlx);
void	draw_line(t_data *img, t_point p0, t_point p1, int color);

int		create_trgb(int t, int r, int g, int b);
int		key_hook(int keycode, t_mlx *mlx);
int		ft_atoi(const char *str);

size_t	ft_strlen(const char *s);
t_point	iso(int x, int y, int z);

#endif
