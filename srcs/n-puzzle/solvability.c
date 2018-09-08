/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvability.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 21:07:38 by afoures           #+#    #+#             */
/*   Updated: 2018/09/08 21:57:14 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int		inversions(t_point *tiles, int size)
{
	int		i;
	int		j;
	int		sum;

	i = 0;
	sum = 0;
	while (i < size * size)
	{
		j = i;
		while (j < size * size)
		{
			if ((tiles[i].x + tiles[i].y * size) < (tiles[j].x + tiles[j].y * size))
				sum++;
			j++;
		}
		i++;
	}
	return (sum);
}

int		is_solvable(t_point *start, t_point *sol, int size)
{
	int		start_inversion;
	int		sol_inversion;

	start_inversion = inversions(start, size);
	sol_inversion = inversions(sol, size);

	if (size % 2)
	{
		start_inversion += start[0].y;
		sol_inversion += sol[0].y;
	}
	return (start_inversion % 2 == sol_inversion % 2);
}
