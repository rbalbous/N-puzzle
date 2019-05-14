/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_star.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 19:31:33 by rbalbous          #+#    #+#             */
/*   Updated: 2019/05/14 20:02:39 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int			calc_eval(t_queue *current, t_board *board)
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

int			check_closed(t_queue *closed, t_queue *current, int size)
{
	int		i;
	int 	ans;

	while (closed != NULL)
	{
		i = 0;
		ans = 0;
		while (i < size * size)
		{
			if (current->board[i].x != closed->board[i].x || current->board[i].y != closed->board[i].y)
			{
				ans = 1;
				break ;
			}
			i++;
		}
		if (ans == 0)
		{
			// ft_printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
			// print_node(closed, size);
			// print_node(current, size);
			// ft_printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
			return (0);
		}
		// if (ft_memcmp(closed->board, current->board, size * size * sizeof(t_point)))
		// {
		// 	ft_printf("ca marche?\n");
		// 	return (0);
		// }
		closed = closed->prev;
	}
	return (1);
}

t_queue		*add_open(t_queue *open, t_queue *new)
{
	t_queue *first;

	first = open;
	if (open == NULL)
	{
		// ft_printf("tag add_open 1\n");
		open = new;
		return (open);
	}
	if ((new->dist + new->eval < open->dist + open->eval) || 
	(new->dist + new->eval == open->dist + open->eval && new->eval < open->eval))
	{
		// ft_printf("tag add_open 2\n");
		new->prev = open;
		open = new;
		return (open);
	}
	while (open->prev != NULL)
	{
		// ft_printf("tag add_open 3\n");
		if ((new->dist + new->eval < open->dist + open->eval) || 
		(new->dist + new->eval == open->dist + open->eval && new->eval < open->eval))
		{
			new->prev = open->prev;
			open->prev = new;
			return (first);
		}
		open = open->prev;
	}
	// ft_printf("tag add_open 4\n");
	new->prev = NULL;
	open->prev = new;
	return (first);
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

t_queue		*add_nodes(t_board *board, t_queue *open, t_queue *current)
{
	t_queue *new;
	int		index;

	index = 0;
	while (index < board->size * board->size)
	{
		// ft_printf("tag add_nodes 1\n");
		if ((current->board[0].x == current->board[index].x && current->board[0].y == current->board[index].y - 1) ||
			(current->board[0].x == current->board[index].x && current->board[0].y == current->board[index].y + 1) ||
			(current->board[0].x == current->board[index].x - 1 && current->board[0].y == current->board[index].y) ||
			(current->board[0].x == current->board[index].x + 1 && current->board[0].y == current->board[index].y))
			{
				// ft_printf("%d %d %d\n", index, current->board[index].x, current->board[index].y);
				// ft_printf("ca rentre?\n");
				new = create_node(board->size, current, 0, index);
				if (check_hashmap(board, new) == 1)
				{
					// ft_printf("tag add_nodes 2\n");
					new->eval = calc_eval(new, board);
					// ft_printf("tag add_nodes 3\n");
					open = add_open(open, new);
					board->cxty_open++;
					// ft_printf("tag add_nodes 4\n");
					// print_chain(open, board->size);
				}
			}
		index++;
	}
	return (open);
	// ft_printf("done\n");
}


void		astar(t_board *board)
{
	int sol;
	t_queue *open;
	t_queue *closed;
	t_queue *current;

	sol = 0;
	open = create_node(board->size, &((t_queue){0, board->board, NULL, -1, 0}), 0, 0);
	closed = NULL;
	while (1)
	{
		current = open;
		// print_node(current, board->size);
		if (open->prev != NULL)
			open = open->prev;
		else
			open = NULL;
		board->cxty_open--;
		// ft_printf("tag astar 1\n");
		if (!(check_solved(board, current)))
			break;
		// ft_printf("tag astar 2\n");
		// ft_printf("tag astar 3\n");
		open = add_nodes(board, open, current);
		// ft_printf("tag astar 4\n");
		current->prev = closed;
		closed = current;
		add_hashmap(board, closed);
		board->cxty_closed++;
		if (closed != NULL)
		{
			// ft_printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			// print_chain(closed, board->size);
			// ft_printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		}
		// print_chain(open, board->size);
		// ft_printf("-------------------------------------------\n");
		// sleep(1);
	}
	// print_chain(open, board->size);
	print_sol(closed, board->size, board);
	// print_snail(board, board->size);
	return ;
}
