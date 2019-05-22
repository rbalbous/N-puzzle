/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 21:21:05 by afoures           #+#    #+#             */
/*   Updated: 2019/05/22 17:10:53 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void	print_board(t_point *board, int size, int tot_size)
{
	int		tab[size][size];
	int		i;
	int		j;

	i = 0;
	while (i < tot_size)
	{
		tab[board[i].y][board[i].x] = i;
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tab[i][j] == 0)
				ft_printf("\033[31m%4d\033[m   ", tab[i][j]);
			else
				ft_printf("%4d   ", tab[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	print_node(t_queue *current, int size)
{
	ft_printf("CURR BOARD :\n");
	print_board(current->board, size, size * size);
	ft_printf("DIST :  %d \nEVAL :  %d \nPREV :  %p\n",
	current->dist, current->eval, current->prev);
}

void	print_coords(t_point *board, int size)
{
	int i;

	i = -1;
	ft_printf("start printing\n");
	while (++i < (size * size))
	{
		ft_printf("%d(%d,%d)\n", i, (board[i]).x, (board[i]).y);
	}
}

void	print_chain(t_queue *queue, int size)
{
	ft_printf("\033[32mchain :\033[m\n");
	while (queue != NULL)
	{
		print_node(queue, size);
		ft_printf("-----------------------\n");
		queue = queue->prev;
	}
}

void	print_sol(t_queue *queue, int size, t_board *board)
{
	int		tot_size;
	int		dist;

	dist = queue->dist + 1;
	ft_printf("MOVE [%d]\n", dist);
	print_board(board->sol, size, size * size);
	ft_printf("\n");
	while (queue->parent != NULL)
	{
		ft_printf("MOVE [%d]\n", queue->dist);
		print_board(queue->board, size, size * size);
		ft_printf("\n");
		queue = queue->parent;
	}
	tot_size = board->cxty_closed + board->cxty_open;
	ft_printf("DIST : \t\t%d\nOPEN SIZE :\t%'d\nCLOSED SIZE :\t%'d\nTOT :\t\t%'d\n", dist, board->cxty_open, board->cxty_closed, tot_size);
}
