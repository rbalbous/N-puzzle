/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npuzzle.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 17:14:02 by afoures           #+#    #+#             */
/*   Updated: 2018/09/08 21:58:21 by afoures          ###   ########.fr       */
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
	t_point	*board;
	int		size;
};

struct		s_queue
{
	t_queue *next;
	t_queue *prev;
	t_point	*board;
	int		dist;
	int		eval;
};

void	print_board(t_point *board, int size);
t_board		*parse_board(char *file);
void		get_sol(t_board *board, t_point point_i, t_point base, int curr);
int			ft_satoi(char **str);
int			is_comment(char *str);
int			is_size(char *str);
int			is_valid_line(char *str);
t_queue		*create_node(int size, t_queue *current, int swap1, int swap2);
int			is_solvable(t_point *start, t_point *sol, int size);

#endif
