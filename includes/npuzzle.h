/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npuzzle.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 17:14:02 by afoures           #+#    #+#             */
/*   Updated: 2018/09/05 23:05:10 by rbalbous         ###   ########.fr       */
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

#endif
