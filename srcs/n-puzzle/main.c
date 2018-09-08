/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 21:20:09 by afoures           #+#    #+#             */
/*   Updated: 2018/09/08 22:02:26 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int		main(int ac, char *av[])
{
	t_board		*board;
	t_queue 	*test;

	if (ac > 1)
	{
		board = parse_board(av[1]);
		ft_printf("Is solvable ? %d\n", is_solvable(board->board, board->sol, board->size));
		test = create_node(board->size, &((t_queue){0, 0, board->board, 0, 0}), 0, 1);
		// print_board(test->board, board->size);
	}
	return (0);
}
