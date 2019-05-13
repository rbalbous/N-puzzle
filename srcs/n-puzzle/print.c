/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 21:21:05 by afoures           #+#    #+#             */
/*   Updated: 2019/05/13 19:55:28 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void	print_board(t_point *board, int size)
{
	int		index;
	int		tot_size;
	int		tab[size][size];
	int		i;
	int		j;

	tot_size = size * size;
	index = 0;
	i = 0;
	while (index < tot_size)
	{
		tab[board[index].y][board[index].x] = index;
		index++;
	}
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tab[i][j] == 0)
				ft_printf("\033[31m%4d\033[m   |", tab[i][j]);
			else
				ft_printf("%4d   |", tab[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	print_node(t_queue *current, int size)
{
	ft_printf("CURR BOARD :\n");
	print_board(current->board, size);
	// ft_printf("PREV BOARD :\n");
	// print_board(current->prev_board, size);
	ft_printf("DIST :  %d \nEVAL :  %d \nPREV :  %p\n", current->dist, current->eval, current->prev);
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

void	print_snail(t_board *board, int size)
{
	int		index;
	int		tot_size;
	int		tab[size][size];
	int		i;
	int		j;

	tot_size = size * size;
	index = 0;
	i = 0;
	while (index < tot_size)
	{
		tab[board->sol[index].y][board->sol[index].x] = index;
		index++;
	}
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tab[i][j] == 0)
				ft_printf("\033[31m%4d\033[m   |", tab[i][j]);
			else
				ft_printf("%4d   |", tab[i][j]);
			j++;		
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
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