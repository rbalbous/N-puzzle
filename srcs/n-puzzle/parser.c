/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 17:13:30 by afoures           #+#    #+#             */
/*   Updated: 2018/09/08 16:18:50 by rbalbous         ###   ########.fr       */
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

int		is_size(char *str)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (ft_ispace(str[i]))
		i++;
	while (ft_isdigit(str[i]))
	{
		check = 1;
		i++;
	}
	if (str[i] == '\0')
		return (check);
	return (0);
}

int		is_valid_line(char *str)
{
	int	i;

	i = 0;
	while (ft_ispace(str[i]) || ft_isdigit(str[i]))
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

int		ft_satoi(char **str)
{
	int count_sign[2];

	count_sign[0] = 0;
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		(*str)++;
	count_sign[1] = (**str == '-' || **str == '+') ? - (*((*str)++) - 44) : 1;
	while (**str >= '0' && **str <= '9')
	{
		count_sign[0] = count_sign[0] * 10 + *((*str)++) - '0';
	}
	return (count_sign[0] * count_sign[1]);
}

t_board	*init_board(t_board *board, int size)
{
	int i;

	if (!(board = ft_memalloc(sizeof(t_board) + 1)))
		return (NULL);
	board->size = size;
	if (!(board->sol = ft_memalloc(sizeof(t_point) * (size * size + 1))))
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
		ft_printf("init done -> %p\n", board);
		return ;
	}
	if (!is_valid_line(str))
		exit(ft_dprintf(2, "Error: line\n"));
	i = -1;
	size = (*board)->size;
	tmp = str;
	while (++i < size && *tmp != '\0')
		(*board)->board[*lines][i] = ft_satoi(&tmp);
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
	ft_printf("file : %s\n", file);
	if ((fd = open(file, O_RDONLY)) <= 2)
	{
		ft_dprintf(2, "Error: %s can't be opened\n", file);
		return (NULL);
	}
	ft_printf("fd -> %d\n", fd);
	lines = 0;
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		ft_printf("line (%d): %s\n", lines, str);
		if (board && lines >= board->size && get_next_line(fd, &str) > 0)
			exit(ft_dprintf(2, "Error: blblbbllblblblb\n"));
		else if (*str == '\0' || (board && lines >= board->size))
			break ;
		if (is_comment(str))
			continue ;
		else
			fill_board(&board, str, &lines);
	}
	if (lines == 0 || lines < board->size - 1)
		exit(ft_dprintf(2, "Error: rtrtrtrtrt\n"));
	if (ret < 0)
		return (NULL);
	get_sol(board, (t_point){1, 0}, (t_point){0, 0}, 1);
	print_board(board);
	return (board);
}
