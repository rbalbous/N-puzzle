/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npuzzle.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 17:14:02 by afoures           #+#    #+#             */
/*   Updated: 2018/09/08 16:18:23 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NPUZZLE_H
 #define NPUZZLE_H

 #include "ft_printf.h"

typedef struct s_board	t_board;
typedef struct s_point	t_point;

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

void	print_board(t_board *board);
t_board	*parse_board(char *file);
void		get_sol(t_board *board, t_point point_i, t_point base, int curr);
int		ft_satoi(char **str);
int		is_comment(char *str);
int		is_size(char *str);
int		is_valid_line(char *str);

#endif
