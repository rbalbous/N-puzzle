/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npuzzle.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 17:14:02 by afoures           #+#    #+#             */
/*   Updated: 2018/09/08 18:18:15 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NPUZZLE_H
 #define NPUZZLE_H

 #include "ft_printf.h"

typedef struct s_board	t_board;
typedef struct s_point	t_point;
typedef struct s_queue	t_queue;

struct		s_point
{
	int x;
	int y;
};

struct		s_board
{
	t_point *sol;
	int		**board;
	int		**distances;
	int		size;
};

struct		s_queue
{
	int		**board;
	int		dist;
}

void	print_board(t_board *board);
t_board	*parse_board(char *file);
void		get_sol(t_board *board, t_point point_i, t_point base, int curr);

#endif
