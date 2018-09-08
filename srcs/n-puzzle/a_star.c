/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_star.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 19:31:33 by rbalbous          #+#    #+#             */
/*   Updated: 2018/09/08 21:57:23 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void		astar(t_board *board)
{
	t_queue		*open;
	t_queue		*closed;

	if (!open)
		open = create_node(board->size, &((t_queue){0, 0, board->board, 0, 0}), 0, 0);
	else
	{
		
	}
	

}

void		add_open(t_queue *open, t_queue *new)
{
	
}