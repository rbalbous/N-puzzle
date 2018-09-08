/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 20:30:42 by rbalbous          #+#    #+#             */
/*   Updated: 2018/09/08 16:18:50 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void		get_sol(t_board *board, t_point point_i, t_point base, int curr)
{
	int		mod;
	int		index;
	
	mod = board->size;
	index = board->size;
	while (1)
	{
		board->sol[curr] = base;
		if (curr++ == 0)
			break;
		if (base.x + point_i.x == board->size || base.x + point_i.x < 0
		|| (point_i.x != 0 && mod == curr - 1))
		{
			point_i = (t_point){0, point_i.x};
			mod += --index;
		}
		else if ((base.y + point_i.y == board->size || base.y + point_i.y < 0
		|| (point_i.y != 0 && mod == curr - 1)) && (mod += index))
			point_i = (t_point){-(point_i.y), 0};
		base = (t_point){base.x + point_i.x, base.y + point_i.y};
		curr = curr % (board->size * board->size);
	}
}

// int			main()
// {
// 	t_board board;
// 	board.sol = malloc(500);
// 	board.size = 5;
// 	int		index = 0;
// 	while (index < 25)
// 	{
// 		board.sol[index].x = -2;
// 		board.sol[index].y = -2;
// 		index++;
// 	}
// 	get_sol(&board, (t_point){1, 0}, (t_point){0, 0}, 1);
// 	index = 0;
// 	while (index < 25)
// 	{
// 		ft_printf("(%d, ", board.sol[index].x);
// 		ft_printf("%d)\n", board.sol[index].y);
// 		index++;
// 	}
// 	return (0);
// }
