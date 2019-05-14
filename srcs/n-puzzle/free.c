/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 20:21:15 by rbalbous          #+#    #+#             */
/*   Updated: 2019/05/14 20:42:31 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void		free_queue(t_queue *queue)
{
	t_queue *tmp;

	while (queue != NULL)
	{
		tmp = queue->prev;
		free(queue->board);
		queue->prev = NULL;
		queue = tmp;
	}
}