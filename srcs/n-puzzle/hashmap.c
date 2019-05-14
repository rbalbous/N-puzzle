/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:54:51 by rbalbous          #+#    #+#             */
/*   Updated: 2019/05/14 20:17:32 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int			cmp_board(t_queue *closed, t_hashlist *current, int size)
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
			return (0);
		}
		closed = closed->prev;
	}
	return (1);
}

int			create_key(t_point *board, int size)
{
	int		count;
	int		index;
	int		i;
	int		j;
	int		tab[size][size];

	count = 0;
	i = 0;	
	index = 0;
	while (index < size * size)
	{
		tab[board[index].y][board[index].x] = index;
		index++;
	}
	while (i < size)
	{
		j = 0;
		while(j < size)
		{
			count += tab[i][j] * (i * size + j + 1); 
			count %= HASH_LENGTH;
			j++;
		}
		i++;
	}
	return (count);
}

t_hashlist	*create_hashnode(t_board *board, t_queue *current)
{
	t_hashlist	*new;

	if (!(new = ft_memalloc(sizeof(t_hashlist))))
		exit(ft_dprintf(2, "malloc error\n"));
	if (!(new->board = ft_memacpy(current->board, board->size * board->size * sizeof(t_point))))
		exit(ft_dprintf(2, "malloc error\n"));
	return (new);
}

int			check_hashmap(t_board *board, t_queue *current)
{
	int			key;
	t_hashlist	*tmp;

	key = create_key(current->board, board->size);
	tmp = board->hash_tab[key];
	if (!(board->hash_tab[key]))
		return (1);
	else
	{
		while (tmp != NULL)
		{
			if (cmp_board(current, tmp, board->size) == 0)
				return (0);
			tmp = tmp->next;
		}
	}
	return (1);
}

void		add_hashmap(t_board *board, t_queue *current)
{
	int		key;
	t_hashlist *new;

	key = create_key(current->board, board->size);
	new = create_hashnode(board, current);
	if (board->hash_tab[key])
		new->next = board->hash_tab[key];
	board->hash_tab[key] = new;
}
