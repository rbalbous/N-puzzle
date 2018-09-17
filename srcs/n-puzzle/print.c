/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 21:21:05 by afoures           #+#    #+#             */
/*   Updated: 2018/09/12 18:24:05 by rbalbous         ###   ########.fr       */
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
		tab[current->board[index].x][current->board[index].y] = index;
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
