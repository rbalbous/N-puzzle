/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_star.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 19:31:33 by rbalbous          #+#    #+#             */
/*   Updated: 2019/05/10 18:33:38 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int			check_solved(t_board *board, t_queue *open)
{
	int		index;
	int		size;

	size = board->size * board->size;
	index = 0;
	while (index < size)
	{
		if (board->sol[index].x != open->board[index].x || board->sol[index].y != open->board[index].y)
			return (1);
		index++;
	}
	return (0);
}

int			check_solved(t_board *board, t_queue *current)
{
	int		index;
	int		size;

	size = board->size * board->size;
	index = 0;
	while (index < size)
	{
		if (board->sol[index].x != current->board[index].x || board->sol[index].y != current->board[index].y)
			return (1);
		index++;
	}
	return (0);
}

void		astar(t_board *board)
{
	int sol;
	t_queue *open;
	t_queue *closed;

	sol = 0;
	open = create_node(board->size, &((t_queue){0, board->board, NULL, -1, 0}), 0, 0);
	closed = create_node(board->size, &((t_queue){0, board->board, NULL, -1, 0}), 0, 0);
	while (sol == 0)
	{
		if (!(check_solved(board, closed)))
			sol = 1;
		
		open = open->prev;
	}
	// print_maillon(open, board->size);
	// print_maillon(closed, board->size);
	// print_snail(board, board->size);
	return ;
}