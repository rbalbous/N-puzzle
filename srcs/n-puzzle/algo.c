/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 19:31:33 by rbalbous          #+#    #+#             */
/*   Updated: 2019/05/22 18:02:35 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int			check_closed(t_queue *closed, t_queue *current, int size)
{
	int		i;
	int		ans;

	while (closed != NULL)
	{
		i = 0;
		ans = 0;
		while (i < size * size)
		{
			if (current->board[i].x != closed->board[i].x
			|| current->board[i].y != closed->board[i].y)
			{
				ans = 1;
				break ;
			}
			i++;
		}
		if (ans == 0)
			return (0);
		closed = closed->prev;
	}
	return (1);
}

t_queue		*add_open(t_queue *open, t_queue *new, int g, int w)
{
	t_queue *first;

	first = open;
	if (open == NULL)
		return (open = new);
	if ((new->dist * g + new->eval * w < open->dist * g + open->eval * w) ||
	(new->dist * g + new->eval * w == open->dist * g + open->eval * w &&
	new->eval * w < open->eval * w))
	{
		new->prev = open;
		return (open = new);
	}
	while (open->prev != NULL)
	{
		if ((new->dist * g + new->eval * w < open->dist * g + open->eval * w) ||
		(new->dist * g + new->eval * w == open->dist * g + open->eval * w &&
		new->eval * w < open->eval * w))
		{
			new->prev = open->prev;
			break ;
		}
		open = open->prev;
	}
	open->prev = new;
	return (first);
}

int			check_s(int cbox, int cboy, int cbix, int cbiy)
{
	if ((cbox == cbix && cboy == cbiy - 1) ||
		(cbox == cbix && cboy == cbiy + 1) ||
		(cbox == cbix - 1 && cboy == cbiy) ||
		(cbox == cbix + 1 && cboy == cbiy))
	{
		return (1);
	}
	return (0);
}

t_queue		*add_nodes(t_board *board, t_queue *open, t_queue *current,
						t_flag *flag)
{
	t_queue	*new;
	int		index;
	int		cbx;
	int		cby;

	cbx = current->board[0].x;
	cby = current->board[0].y;
	index = 0;
	while (index < board->size * board->size)
	{
		if (check_s(cbx, cby, current->board[index].x, current->board[index].y))
		{
			new = create_node(board->size, current, 0, index);
			if (check_hashmap(board, new) == 1)
			{
				new->eval = flag->h[flag->heuristic](new, board);
				open = add_open(open, new, flag->greed, flag->weight);
				board->cxty_open++;
			}
		}
		index++;
	}
	return (open);
}

void		algo(t_board *board, t_flag *flag, int size)
{
	t_queue	*open;
	t_queue	*closed;
	t_queue	*current;

	open = create_node(size, &((t_queue){0, board->board, NULL, -1, 0}), 0, 0);
	closed = NULL;
	while (1)
	{
		current = open;
		if (open->prev != NULL)
			open = open->prev;
		else
			open = NULL;
		board->cxty_open--;
		if (!(check_solved(board, current)))
			break ;
		open = add_nodes(board, open, current, flag);
		current->prev = closed;
		closed = current;
		add_hashmap(board, closed);
		board->cxty_closed++;
	}
	if (flag->disp == 1)
		print_sol(closed, size, board);
	return ;
}
