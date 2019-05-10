/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 21:20:09 by afoures           #+#    #+#             */
/*   Updated: 2019/05/10 15:45:18 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int		main(int ac, char *av[])
{
	t_board		*board;

	if (ac > 1)
	{
		board = parse_board(av[1]);
		ft_printf("Is solvable ? %d\n", is_solvable(board->board, board->sol, board->size));
		astar(board);
		// print_board(test->board, board->size);
	}
	return (0);
}
