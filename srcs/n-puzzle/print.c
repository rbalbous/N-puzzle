/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 21:21:05 by afoures           #+#    #+#             */
/*   Updated: 2018/09/17 18:26:13 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void	print_maillon(t_queue *current, int size)
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
		tab[current->board[index].y][current->board[index].x] = index;
		index++;
	}
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_printf("%-5d|", tab[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("DIST : | %d |\nEVAL : | %d |\nNEXT : | %p |\nPREV : | %p |\n", current->dist, current->eval, current->next, current->prev);
}

void	print_board(t_point *board, int size)
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
			ft_printf("%-5d|", tab[i][j]);
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
	while (queue->prev != NULL)
	{
		queue = queue->prev;
	}
	while (queue != NULL)
	{
		print_maillon(queue, size);
		ft_printf("-----------------------\n");
		queue = queue->next;
	}
}