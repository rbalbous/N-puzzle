/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npuzzle.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 17:14:02 by afoures           #+#    #+#             */
/*   Updated: 2018/09/05 17:56:18 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NPUZZLE_H
 #define NPUZZLE_H

typedef struct s_board	t_board;

struct		s_board
{
	int		*board;
	int		*distances;
	int		size;
};

#endif
