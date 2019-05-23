/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 17:13:30 by afoures           #+#    #+#             */
/*   Updated: 2019/05/23 18:39:58 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int		parse_flags(char **av, int ac, t_flag *flag, int i)
{
	int		new_value;

	new_value = 0;
	if (av[i][1] == 's')
		flag->disp = 1;
	else if (av[i][1] == 'u' && flag->weight == 1)
		flag->weight = 0;
	else if (av[i][1] == 'g' && flag->greed == 1)
		flag->greed = 0;
	else if (av[i][1] == 'w' && flag->weight == 1)
	{
		if (i + 1 >= ac || av[i + 1][0] == '-')
			flag->weight = 2;
		else
		{
			i++;
			if ((new_value = ft_atoi(av[i])) <= 10 && new_value != 0)
				flag->weight = new_value;
			else
				disp_usage();
		}
	}
	else
		disp_usage();
	return (i);
}

void	parse_arg(char **av, int ac, t_flag *flag)
{
	int		i;

	i = 2;
	while (i < ac)
	{
		if (av[i][0] != '-')
			disp_usage();
		i = parse_flags(av, ac, flag, i);
		if (av[i][1] == '-')
		{
			if (!(ft_strcmp(av[i], "--manhattan")))
				flag->heuristic = 0;
			else if (!(ft_strcmp(av[i], "--missplaced")))
				flag->heuristic = 1;
			else if (!(ft_strcmp(av[i], "--axes")))
				flag->heuristic = 2;
			else
				disp_usage();
		}
		i++;
	}
}

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
		if (!is_size(str) || (size = ft_atoi(str)) < 3 || size > 10)
			exit(ft_dprintf(2, "Error: size\n"));
		*board = init_board(*board, size);
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

t_board	*parse_board(char *file, t_board *board, int lines)
{
	char	*str;
	int		fd;
	int		ret;

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
		if (str != NULL)
			free(str);
	}
	if (ret < 0 || lines == 0 || lines < board->size - 1)
		exit(ft_dprintf(2, "Error: rtrtrtrtrt\n"));
	get_sol(board, (t_point){1, 0}, (t_point){0, 0}, 1);
	return (board);
}
