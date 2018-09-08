/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_satoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 16:17:42 by afoures           #+#    #+#             */
/*   Updated: 2018/09/08 16:20:26 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int		ft_satoi(char **str)
{
	int count_sign[2];

	count_sign[0] = 0;
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		(*str)++;
	count_sign[1] = (**str == '-' || **str == '+') ? -(*((*str)++) - 44) : 1;
	while (**str >= '0' && **str <= '9')
	{
		count_sign[0] = count_sign[0] * 10 + *((*str)++) - '0';
	}
	return (count_sign[0] * count_sign[1]);
}
