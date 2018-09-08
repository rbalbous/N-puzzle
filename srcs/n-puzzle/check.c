/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 16:17:12 by afoures           #+#    #+#             */
/*   Updated: 2018/09/08 16:18:06 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

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
