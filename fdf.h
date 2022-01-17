/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:43:33 by nerraou           #+#    #+#             */
/*   Updated: 2022/01/15 16:24:51 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
#define FDF_H

#include <mlx.h>
#include <stdio.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int 	line_length;
	int		endian;
}					t_data;



#endif
