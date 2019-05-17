/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 21:20:09 by afoures           #+#    #+#             */
/*   Updated: 2019/05/17 19:29:16 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int		main(int ac, char *av[])
{
	t_board		*board;
	t_flags		flags;

	flags = (t_flags){1, 1, 0, 0};
	if (ac > 1)
	{
		board = parse_board(av[1]);
		if (ac > 2)
			flags = parse_args(av, ac, board);
		// print_coords(board->board, board->size);
		// print_coords(board->sol, board->size);
		if (!(is_solvable(board->board, board->sol, board->size)))
		{
			ft_printf("Unsolvable\n");
			return (0);
		}
		astar(board);
	}
	return (0);
}
