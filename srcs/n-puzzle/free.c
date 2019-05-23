/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 20:21:15 by rbalbous          #+#    #+#             */
/*   Updated: 2019/05/23 18:45:14 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void		free_node(t_queue *queue)
{
	free(queue->board);
	queue->prev = NULL;
	queue->parent = NULL;
	free(queue);
}

void		free_queue(t_queue *queue)
{
	t_queue *tmp;

	while (queue != NULL)
	{
		tmp = queue->prev;
		free(queue->board);
		queue->prev = NULL;
		queue->parent = NULL;
		free(queue);
		queue = tmp;
	}
	free(queue);
	free(tmp);
}

void		free_hashlist(t_board *board)
{
	int			i;
	t_hashlist	*tmp;

	i = 0;
	while (i < HASH_LENGTH)
	{
		while (board->hash_tab[i] != NULL)
		{
			free(board->hash_tab[i]->board);
			tmp = board->hash_tab[i]->next;
			board->hash_tab[i]->next = NULL;
			free(board->hash_tab[i]);
			board->hash_tab[i] = tmp;
		}
		i++;
	}
}

void		free_board(t_board *board)
{
	free(board->sol);
	free(board->board);
	free_hashlist(board);
}
