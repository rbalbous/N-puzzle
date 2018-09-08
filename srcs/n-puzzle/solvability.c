/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvability.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 21:07:38 by afoures           #+#    #+#             */
/*   Updated: 2018/09/08 21:21:42 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int		*cpy_start(int *start, int size)
{
	int		*start_cpy;
	int		i;

	if (!(start_cpy = malloc(sizeof(int) * (size * size + 1))))
		exit(-1);// return (NULL);
	i = 0;
	while (i < size)
	{
		ft_memcpy(start_cpy + i * size, start[i], size * sizeof(int));
		i++;
	}
	return (start_cpy);
}

int		is_solvable(int *start, int *sol, int size)
{
	int		start_inversion;
	int		sol_inversion;
	int		*start_cpy;

	start_cpy = cpy_start(start, size)
	start_inversion = inversions(start_cpy);
	sol_inversion = inversions(sol);

	if ()
	return ()
}
