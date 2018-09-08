/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_star.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 19:31:33 by rbalbous          #+#    #+#             */
/*   Updated: 2018/09/08 22:22:00 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void		astar(t_board *board)
{
	t_queue		*open;
	t_queue		*new;
	t_queue		*closed;

	if (!open)
		open = create_node(board->size, &((t_queue){0, 0, board->board, 0, 0}), 0, 0);
	else
	{
		while (open != NULL)
		{
		new = create_node(board->size, open, 0, 0);
		add_open(open, new);
		}
	}
}

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