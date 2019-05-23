/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:49:09 by rbalbous          #+#    #+#             */
/*   Updated: 2019/05/23 16:36:34 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int			eval_manhattan(t_queue *new, t_board *board)
{
	int		tot;
	int		index;

	tot = 0;
	index = 1;
	while (index < board->size * board->size)
	{
		tot += abs(new->board[index].x - board->sol[index].x) +
		abs(new->board[index].y - board->sol[index].y);
		index++;
	}
	return (tot);
}

int			eval_missplaced(t_queue *new, t_board *board)
{
	int		tot;
	int		index;

	tot = 0;
	index = 1;
	while (index < board->size * board->size)
	{
		tot += ((new->board[index].x != board->sol[index].x) &&
		(new->board[index].y != board->sol[index].y));
		index++;
	}
	return (tot);
}

int			eval_axes(t_queue *new, t_board *board)
{
	int		tot;
	int		index;

	tot = 0;
	index = 1;
	while (index < board->size * board->size)
	{
		tot += ((new->board[index].x != board->sol[index].x) ||
		(new->board[index].y != board->sol[index].y)) +
		((new->board[index].x != board->sol[index].x) &&
		(new->board[index].y != board->sol[index].y));
		index++;
	}
	return (tot);
}
