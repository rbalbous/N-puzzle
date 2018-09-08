/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 21:21:05 by afoures           #+#    #+#             */
/*   Updated: 2018/09/08 21:28:10 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

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
