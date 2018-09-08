/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 21:21:05 by afoures           #+#    #+#             */
/*   Updated: 2018/09/08 19:29:05 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void	print_board(int **board, int size)
{
	int i;
	int j;

	i = -1;
	ft_printf("start printing\n");
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			ft_printf("%4d ", board[i][j]);
		}
		ft_printf("\n");
	}
	// i = -1;
	// while (++i < (board->size * board->size))
	// {
	// 	ft_printf("%d(%d,%d)\n", i, (board->sol[i]).x, (board->sol[i]).y);
	// }
}
