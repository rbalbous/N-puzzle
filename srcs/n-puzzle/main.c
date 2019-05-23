/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 21:20:09 by afoures           #+#    #+#             */
/*   Updated: 2019/05/23 18:47:22 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int		main(int ac, char *av[])
{
	t_board		*board;
	t_flag		flag;

	flag = (t_flag){1, 1, 0, 0, {NULL}};
	init_h(flag.h);
	if (ac > 1)
	{
		board = parse_board(av[1], NULL, 0);
		if (ac > 2)
			parse_arg(av, ac, &flag);
		if (!(is_solvable(board->board, board->sol, board->size)))
		{
			ft_printf("Unsolvable\n");
			return (0);
		}
		algo(board, &flag, board->size);
		free_board(board);
	}
	return (0);
}
