/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 21:21:05 by afoures           #+#    #+#             */
/*   Updated: 2018/09/08 15:28:55 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void	print_board(t_board *board)
{
	int i;
	int j;

	i = -1;
	ft_printf("start printing\n");
	while (++i < board->size)
	{
		j = -1;
		while (++j < board->size)
		{
			ft_printf("%4d ", board->board[i][j]);
		}
		ft_printf("\n");
	}
	i = -1;
	while (++i < (board->size * board->size))
	{
		ft_printf("%d(%d,%d)\n", i, (board->sol[i]).x, (board->sol[i]).y);
	}
}
