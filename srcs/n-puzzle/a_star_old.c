/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_star_old.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 19:31:33 by rbalbous          #+#    #+#             */
/*   Updated: 2019/05/10 18:37:16 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void	add_open(t_queue *open, t_queue *new)
{
	t_queue *tmp;

	// ft_printf("%d\n", new->eval);
	while (open->next != NULL)
	{
		open = open->next;
	}
	// ft_printf("nd + nv : %d | od + ov : %d\n", new->eval + new->dist, open->dist + open->eval);
	if (new->dist + new->eval <= open->dist + open->eval && new->dist < open->dist)
	{
		// ft_printf("add en last\n");
		new->prev = open;
		open->next = new;
		return ;
	}
	while (open->prev != NULL)
	{
		if (new->dist + new->eval < open->dist + open->eval && new->dist <= open->dist)
		{
			// ft_printf("add entre\n");
			tmp = open->next;
			open->next = new;
			new->prev = open;
			new->next = tmp;
			tmp->prev = new;
			return ;
		}
		open = open->prev;
	}
	if (new->dist + new->eval < open->dist + open->eval && new->dist <= open->dist)
	{
		// ft_printf("add entre\n");
		tmp = open->next;
		open->next = new;
		new->prev = open;
		new->next = tmp;
		tmp->prev = new;
		return ;
	}
	else
	{
		// ft_printf("add debut\n");
		new->next = open;
		open->prev = new;
	}
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

int			check_side(t_queue *new, t_queue *closed, int size)
{
	int		index;

	index = 0;
	while (index < size * size)
	{
		if (new->board[index].x != closed->board[index].x || new->board[index].y != closed->board[index].y)
			return (0);
		index++;
	}
	return (1);
}

int			fill_queue(t_board *board, t_queue *open, t_queue *closed)
{
	t_queue *new;
	int		index;

	index = 0;
	if (!check_solved(board, open))
		return (0);
	// ft_printf("zero %d %d\n", open->board[0].x, open->board[0].y);
	while (index < board->size * board->size)
	{
		if ((open->board[0].x == open->board[index].x && open->board[0].y == open->board[index].y - 1) ||
			(open->board[0].x == open->board[index].x && open->board[0].y == open->board[index].y + 1) ||
			(open->board[0].x == open->board[index].x - 1 && open->board[0].y == open->board[index].y) ||
			(open->board[0].x == open->board[index].x + 1 && open->board[0].y == open->board[index].y))
			{
				// ft_printf("%d %d %d\n", index, open->board[index].x, open->board[index].y);
				// ft_printf("ca rentre?\n");
				new = create_node(board->size, open, 0, index);
				new->eval = calc_eval(new, board);
				if (!check_side(new, closed, board->size))
				{
					add_open(open, new);
					// ft_printf("\033[33mfill queue :\033[m\n");
					// print_maillon(new, board->size);
					// ft_printf("\033[33mqueue filled :\033[m\n");
					// print_maillon(open, board->size);
				}
			}
		index++;
	}
	// ft_printf("done\n");
	return (1);
}

void		astar(t_board *board)
{
	t_queue		*open;
	t_queue		*closed;
	t_queue		*tmp;
	int			ret;

	ret = 0;
	open = create_node(board->size, &((t_queue){0, 0, board->board, -1, 0}), 0, 0);
	closed = create_node(board->size, &((t_queue){0, 0, board->board, -1, 0}), 0, 0);
	// print_maillon(open, board->size);
	while (open != NULL)
	{
		// ft_printf("boucle\n");
		if (!fill_queue(board, open, closed))
		{
			ft_printf("ca return?\n");
			open->next = NULL;
			closed->next = open;
			print_chain(closed, board->size);
			return ;
		}
		//print_chain(open, board->size);
		if (open->next != NULL)
		{
			tmp = open->prev;
			open->prev = closed;
			closed->next = open;
			closed = closed->next;
			open = tmp;
			open->next = NULL;
			// print_maillon(closed, board->size);
			while (open->next != NULL)
			{
				// ft_printf("boucle 2\n");
				open = open->next;
			}
		}
		else
		{
			// ft_printf("check prev\n");
			while (closed->prev != NULL && open->dist > closed->dist)
			{
				tmp = closed->prev;
				if (tmp->eval > closed->eval && open->dist == closed->dist)
					break ;
				closed = closed->prev;
				closed->next = NULL;
			}
			// ft_printf("working\n");
			tmp = open->prev;
			open->prev = closed;
			closed->next = open;
			closed = closed->next;
			open = tmp;
			open->next = NULL;
			open = tmp;
			// ft_printf("prev checked\n");
		}
			// ft_printf("\033[31mclosed :\033[m\n");