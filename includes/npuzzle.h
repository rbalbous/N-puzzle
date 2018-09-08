/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npuzzle.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 17:14:02 by afoures           #+#    #+#             */
/*   Updated: 2018/09/08 21:05:56 by rbalbous         ###   ########.fr       */
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
	t_queue *next;
	t_queue *prev;
	t_point *zero;
	int		**board;
	int		dist;
	int		eval;
};

void		print_board(int **board, int size);
t_board		*parse_board(char *file);
void		get_sol(t_board *board, t_point point_i, t_point base, int curr);
int			ft_satoi(char **str);
int			is_comment(char *str);
int			is_size(char *str);
int			is_valid_line(char *str);
t_queue		*create_node(int size, t_queue *current, t_point swap1, t_point swap2);

#endif
