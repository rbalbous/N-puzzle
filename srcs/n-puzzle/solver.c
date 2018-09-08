/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 20:30:42 by rbalbous          #+#    #+#             */
/*   Updated: 2018/09/08 18:34:57 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void		get_sol(t_board *board, t_point point_i, t_point base, int curr)
{
	int		mod;
	int		index;
	
	mod = board->size;
	index = board->size;
	while (1)
	{
		board->sol[curr] = base;
		if (curr++ == 0)
			break;
		if (base.x + point_i.x == board->size || base.x + point_i.x < 0
		|| (point_i.x != 0 && mod == curr - 1))
		{
			point_i = (t_point){0, point_i.x};
			mod += --index;
		}
		else if (base.y + point_i.y == board->size || base.y + point_i.y < 0
		|| (point_i.y != 0 && mod == curr - 1))
		{
			point_i = (t_point){-(point_i.y), 0};
			mod += index;
		}
		base = (t_point){base.x + point_i.x, base.y + point_i.y};
		curr = curr % (board->size * board->size);
	}
}
