/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 16:17:12 by afoures           #+#    #+#             */
/*   Updated: 2019/05/23 18:44:40 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void	disp_usage(void)
{
	ft_printf("\t-s : Display solution\n\t-u : Sets weight to 0\n");
	ft_printf("\t-g : Sets greed to 0\n\t");
	ft_printf("-w N: Sets weight to N value, sets 2 when no N is specified\n");
	ft_printf("\t--manhattan : Sets heuristic to Manhattan\n");
	ft_printf("\t--misplaced : Sets heuristic to Misplaced\n");
	ft_printf("\t--axes : Sets heuristic to Axes\n");
	exit(0);
}

int		is_comment(char *str)
{
	int	i;

	i = 0;
	while (ft_ispace(str[i]))
		i++;
	if (str[i] == '#')
	{
		free(str);
		return (1);
	}
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
