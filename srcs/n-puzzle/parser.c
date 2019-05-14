/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 17:13:30 by afoures           #+#    #+#             */
/*   Updated: 2019/05/14 18:53:38 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

t_board	*init_board(t_board *board, int size)
{
	if (!(board = ft_memalloc(sizeof(t_board) + 1)))
		return (NULL);
	board->size = size;
	board->cxty_open = 0;
	board->cxty_closed = 0;
	if (!(board->sol = ft_memalloc(sizeof(t_point) * (size * size + 1))))
		return (NULL);
	if (!(board->board = ft_memalloc(sizeof(t_point) * (size * size + 1))))
		return (NULL);
	return (board);
}

void	fill_board(t_board **board, char *str, int *lines)
{
	int			size;
	int			i;
	char		*tmp;

	size = 0;
	if (*board == NULL)
	{
		if (!is_size(str) || (size = ft_atoi(str)) < 3)
			exit(ft_dprintf(2, "Error: size\n"));
		*board = init_board(*board, size);
		// ft_printf("init done -> %p\n", board);
		return ;
	}
	if (!is_valid_line(str))
		exit(ft_dprintf(2, "Error: line\n"));
	i = -1;
	size = (*board)->size;
	tmp = str;
	while (++i < size && *tmp != '\0')
		(*board)->board[ft_satoi(&tmp)] = (t_point){i, *lines};
	if (i < size)
		exit(ft_dprintf(2, "Error: size2\n"));
	*lines += 1;
}

t_board	*parse_board(char *file)
{
	char	*str;
	int		fd;
	int		ret;
	t_board	*board;
	int 	lines;

	board = NULL;
	lines = 0;
	if ((fd = open(file, O_RDONLY)) <= 2)
		exit(ft_dprintf(2, "Error: %s can't be opened\n", file));
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		if (board && lines >= board->size && get_next_line(fd, &str) > 0)
			exit(ft_dprintf(2, "Error: blblbbllblblblb\n"));
		else if (*str == '\0' || (board && lines >= board->size))
			break ;
		if (is_comment(str))
			continue ;
		else
			fill_board(&board, str, &lines);
	}
	if (ret < 0 || lines == 0 || lines < board->size - 1)
		exit(ft_dprintf(2, "Error: rtrtrtrtrt\n"));
	get_sol(board, (t_point){1, 0}, (t_point){0, 0}, 1);
	// print_board(board->board, board->size); // affichage
	return (board);
}
