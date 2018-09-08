/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 21:20:09 by afoures           #+#    #+#             */
/*   Updated: 2018/09/08 21:43:24 by rbalbous         ###   ########.fr       */
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
		test = create_node(board->size, &((t_queue){0, 0, board->board, 0, 0}), 0, 1);
		print_board(test->board, board->size);
	}
	return (0);
}
