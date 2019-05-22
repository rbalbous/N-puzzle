/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 20:30:42 by rbalbous          #+#    #+#             */
/*   Updated: 2019/05/22 17:47:44 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void		init_h(int (*h[3])())
{
	h[0] = eval_manhattan;
	h[1] = eval_missplaced;
	h[2] = eval_axes;
}

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
			break ;
		if (base.x + point_i.x == board->size || base.x + point_i.x < 0 ||
			(point_i.x != 0 && mod == curr - 1))
		{
			point_i = (t_point){0, point_i.x};
			mod += --index;
		}
		else if (base.y + point_i.y == board->size || base.y + point_i.y < 0 ||
			(point_i.y != 0 && mod == curr - 1))
		{
			point_i = (t_point){-(point_i.y), 0};
			mod += index;
		}
		base = (t_point){base.x + point_i.x, base.y + point_i.y};
		curr = curr % (board->size * board->size);
	}
}

void		swap_tpoint(t_queue *current, int swap1, int swap2)
{
	t_point		tmp;

	tmp = current->board[swap1];
	current->board[swap1] = current->board[swap2];
	current->board[swap2] = tmp;
}

t_queue		*create_node(int s, t_queue *current, int swap1, int swap2)
{
	t_queue		*new;

	if (!(new = ft_memalloc(sizeof(t_queue))))
		exit(ft_dprintf(2, "malloc error\n"));
	new->parent = current;
	if (!(new->board = ft_memacpy(current->board, s * s * sizeof(t_point))))
		exit(ft_dprintf(2, "malloc error\n"));
	swap_tpoint(new, swap1, swap2);
	new->dist = current->dist + 1;
	new->eval = current->eval;
	new->prev = NULL;
	return (new);
}

int			check_solved(t_board *board, t_queue *current)
{
	int		index;
	int		size;

	size = board->size * board->size;
	index = 0;
	while (index < size)
	{
		if (board->sol[index].x != current->board[index].x ||
		board->sol[index].y != current->board[index].y)
			return (1);
		index++;
	}
	return (0);
}
