/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npuzzle.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 17:14:02 by afoures           #+#    #+#             */
/*   Updated: 2019/05/23 18:45:57 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NPUZZLE_H
# define NPUZZLE_H

# include "ft_printf.h"

# define HASH_LENGTH 10000

typedef struct s_board		t_board;
typedef struct s_point		t_point;
typedef struct s_queue		t_queue;
typedef struct s_hash		t_hash;
typedef struct s_hashlist	t_hashlist;
typedef struct s_flag		t_flag;

struct		s_point
{
	int x;
	int y;
};

struct		s_board
{
	t_point		*sol;
	t_point		*board;
	t_hashlist	*hash_tab[HASH_LENGTH];
	int			cxty_open;
	int			cxty_closed;
	int			size;
};

struct		s_flag
{
	int		greed;
	int		weight;
	int		disp;
	int		heuristic;
	int		(*h[3])();
};

struct		s_queue
{
	t_queue *prev;
	t_point	*board;
	t_queue *parent;
	int		dist;
	int		eval;
};

struct		s_hashlist
{
	t_hashlist	*next;
	t_point		*board;
};

void		print_board(t_point *board, int size, int tot_size);
t_board		*parse_board(char *file, t_board *board, int lines);
void		get_sol(t_board *board, t_point point_i, t_point base, int curr);
int			ft_satoi(char **str);
int			is_comment(char *str);
int			is_size(char *str);
int			is_valid_line(char *str);
t_queue		*create_node(int size, t_queue *current, int swap1, int swap2);
int			is_solvable(t_point *start, t_point *sol, int size);
int			check_solved(t_board *board, t_queue *current);
void		algo(t_board *board, t_flag *flag, int size);
void		print_node(t_queue *current, int size);
void		print_snail(t_board *board, int size);
void		print_chain(t_queue *queue, int size);
void		print_coords(t_point *board, int size);
void		print_sol(t_queue *queue, int size, t_board *board, int disp);
void		add_hashmap(t_board *board, t_queue *current);
int			check_hashmap(t_board *board, t_queue *current);
t_hashlist	*create_hashnode(t_board *board, t_queue *current);
void		parse_arg(char **av, int ac, t_flag *flag);
int			eval_manhattan(t_queue *new, t_board *board);
int			eval_missplaced(t_queue *new, t_board *board);
int			eval_axes(t_queue *new, t_board *board);
void		init_h(int (*h[3])());
void		free_queue(t_queue *queue);
void		free_board(t_board *board);
void		free_node(t_queue *queue);
void		disp_usage(void);

#endif
