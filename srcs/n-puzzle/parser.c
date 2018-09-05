/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 17:13:30 by afoures           #+#    #+#             */
/*   Updated: 2018/09/05 21:19:46 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

// void	parse_args(int ac, char *av[])
// {
// 	int i;

// 	i = 0;
// 	while (++i < ac)
// 		;
// }

int		is_comment(char *str)
{
	int	i;

	i = 0;
	while (ft_ispace(str[i]))
		i++;
	if (str[i] == '#')
		return (1);
	return (0);
}

t_board	*init_board(t_board *board, int size)
{
	int i;

	if (!(board = ft_memalloc(sizeof(t_board) + 1)))
		return (NULL);
	board->size = size;
	if (!(board->sol = ft_memset(ft_memalloc(sizeof(int)
		* (size * size + 1)), -1, size * size)))
		return (NULL);
	i = -1;
	if (!(board->board = ft_memalloc(sizeof(int *) * (size + 1))))
		return (NULL);
	if (!(board->distances = ft_memalloc(sizeof(int *) * (size + 1))))
		return (NULL);
	while (++i < size)
	{
		if (!(board->board[i] = ft_memalloc(sizeof(int) * (size + 1))))
			return (NULL);
		if (!(board->distances[i] = ft_memalloc(sizeof(int) * (size + 1))))
			return (NULL);
	}
	return (board);
}

void	fill_board(t_board **board, char *str)
{
	int		size;

	if (*board == NULL)
	{
		size = ft_atoi(str);

	}

}

t_board	*parse_board(char *file)
{
	char	*str;
	int		fd;
	int		ret;
	t_board	*board;

	board = NULL;
	if ((fd = open(file, O_RDONLY) < 0))
	{
		ft_dprintf(2, "Error: %s can't be opened\n", file);
		return (NULL);
	}
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		if (is_comment(str))
			continue ;
		else
			fill_board(&board, str);
	}
	if (ret < 0)
		return (NULL);
	return (board);
}
