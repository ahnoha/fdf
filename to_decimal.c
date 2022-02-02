/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:22:49 by nerraou           #+#    #+#             */
/*   Updated: 2022/02/02 17:41:13 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int  to_decimal(char *str)
{
	int num;
	int decimal;
	int i;
	int len;

	decimal = 0;
	i = 1;
	len = ft_strlen(str) - 1;
	while (len >= 0)
	{
		if (str[len] >= 'A' && str[len] <= 'F')
			num = (str[len] - 'A') + 10;
		else if (str[len] >= '0' && str[len] <= '9')
			num = str[len] - '0';	
		decimal += num * (i);
		i *= 16;
		len--;
	}
	return (decimal);
}
