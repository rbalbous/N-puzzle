/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 17:13:30 by afoures           #+#    #+#             */
/*   Updated: 2018/09/05 18:09:12 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void	parse_args(int ac, char *av[])
{
	int i;

	i = 0;
	while (++i < ac)
	{
	}
}

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

t_board	*parse_board(char *file)
{
	char	*str;
	int		fd;
	int		ret;

	if ((fd = open(file, O_RDONLY) < 0)
	{
		ft_dprintf(2, "Error: %s can't be opened\n", file);
		return (NULL);
	}
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		if (is_comment(str))
			continue ;
	}
	if (ret < 0)
		return (NULL);
	return (board);
}
