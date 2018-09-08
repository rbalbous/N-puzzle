/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 20:30:42 by rbalbous          #+#    #+#             */
/*   Updated: 2018/09/08 21:20:10 by rbalbous         ###   ########.fr       */
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

void		swap_tpoint(t_queue *current, t_point swap1, t_point swap2)
{
	int		tmp;

	tmp = current->board[swap1.x][swap1.y];
	current->board[swap1.x][swap1.y] = current->board[swap2.x][swap2.y];
	current->board[swap2.x][swap2.y] = tmp;
}

t_queue		*create_node(int size, t_queue *current, t_point swap1, t_point swap2)
{
	t_queue		*new;

	new = ft_memalloc(sizeof(t_queue));
	new->board = ft_memacpy(current->board, size * 32);
	swap_tpoint(new, swap1, swap2);
	new->dist = current->dist + 1;
	new->zero = &((t_point){new->board[0][0], new->board[0][1]});
	
	return (new);
}
