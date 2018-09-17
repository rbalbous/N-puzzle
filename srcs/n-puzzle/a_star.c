/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_star.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 19:31:33 by rbalbous          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/09/08 22:24:55 by rbalbous         ###   ########.fr       */
=======
/*   Updated: 2018/09/12 18:21:21 by rbalbous         ###   ########.fr       */
>>>>>>> a640f1cecaaef3fd62b7db10eacf72651f5a8e96
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

t_queue		*add_open(t_queue *open, t_queue *new)
{
	t_queue *last = open;

	if (new->dist + new->eval > open->dist + open->eval && new->dist <= open->dist)
	{
		new->prev = open;
		open->next = new;
		return (new);
	}
	while (open->prev != NULL)
	{
		if (new->dist + new->eval > open->dist + open->eval && new->dist <= open->dist)
		{
			new->prev = open;
			open = open->next;
			new->next = open;
			return (last);
		}
		open = open->prev;
	}
	new->next = open;
	open->prev = new;
	return (last);
}

int			check_prev(t_board *board, t_queue *open, t_queue *closed)
{
	int		index;
	int		count;
	int		size;
	
	size = board->size * board->size;
	index = 0;
	count = 0;
	while (index < size)
	{
		if (open->board[index].x != closed->board[index].x &&
			open->board[index].y != closed->board[index].y)
		{
			if (++count > 2)
				return (1);
		}
		index++;
	}
	return (count == 0);
}

int			calc_eval(t_queue *current, t_board *board)
{
	int		tot;
	int		index;

	tot = 0;
	index = 0;
	while (index < board->size * board->size)
	{
		tot += abs(current->board[index].x - board->sol[index].x + current->board[index].y - board->sol[index].y);
		index++;
	}
	return (tot);
}

int			fill_queue(t_board *board, t_queue *open)
{
	t_queue *new;
	int		index;

	index = 1;
	if (board->sol == open->board)
		return (0);
	while (index < board->size * board->size - 1)
	{
		ft_printf("fill queue %d\n", index);
		if ((open->board[0].x == open->board[index].x && open->board[0].y == open->board[index].y - 1) ||
			(open->board[0].x == open->board[index].x && open->board[0].y == open->board[index].y + 1) ||
			(open->board[0].x == open->board[index].x - 1 && open->board[0].y == open->board[index].y) ||
			(open->board[0].x == open->board[index].x + 1 && open->board[0].y == open->board[index].y))
			{
				ft_printf("ca rentre?\n");
				new = create_node(board->size, open, 0, index);
				new->eval = calc_eval(new, board);
				print_maillon(new, board->size);
				add_open(open, new);
			}
		index++;
	}
	ft_printf("done\n");
	return (1);
}

void		astar(t_board *board)
{
	t_queue		*open;
	t_queue		*closed;
	int			ret;

	ret = 0;
	open = create_node(board->size, &((t_queue){0, 0, board->board, 0, 0}), 0, 0);
	print_maillon(open, board->size);
	while (open != NULL)
	{
		ft_printf("boucle\n");
		if (!fill_queue(board, open))
			return;
		if (open->next != NULL)
		{
			while (open->next != NULL)
			{
				ft_printf("boucle 2\n");
				open = open->next;
			}
		}
		else
		{
			open = open->prev;
			open->next = NULL;
			while (check_prev(board, open, closed))
			{
				closed = closed->prev;
				closed->next = NULL;
			}
		}
	}
	print_board(closed->board, board->size);
}
