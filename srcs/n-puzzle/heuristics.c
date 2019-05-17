/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:49:09 by rbalbous          #+#    #+#             */
/*   Updated: 2019/05/17 19:23:37 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int			eval_manhattan(t_queue *current, t_board *board)
{
	int		tot;
	int		index;

	tot = 0;
	index = 1;
	while (index < board->size * board->size)
	{
		tot += abs(current->board[index].x - board->sol[index].x) + abs(current->board[index].y - board->sol[index].y);
		index++;
	}
	return (tot);
}

int			eval_missplaced(t_queue *current, t_board *board)
{
	int		tot;
	int		index;

	tot = 0;
	index = 1;
	while (index < board->size * board->size)
	{
		tot += ((current->board[index].x == board->sol[index].x) && (current->board[index].y == board->sol[index].y));
		index++;
	}
	return (tot);
}

int			eval_axes(t_queue *current, t_board *board)
{
	int		tot;
	int		index;

	tot = 0;
	index = 1;
	while (index < board->size * board->size)
	{
		tot += ((current->board[index].x == board->sol[index].x) || (current->board[index].y == board->sol[index].y)) + 
		((current->board[index].x == board->sol[index].x) && (current->board[index].y == board->sol[index].y));
		index++;
	}
	return (tot);
}