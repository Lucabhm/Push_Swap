/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerparsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:58:46 by lbohm             #+#    #+#             */
/*   Updated: 2024/01/18 12:56:37 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	check_max_min(char *str)
{
	int	nbr;
	int	strnbr;

	nbr = ft_strlen(str);
	strnbr = ft_atoi(str);
	if ((nbr == 11 && str[0] == '-' && strnbr > 0)
		|| (nbr > 11 && str[0] == '-')
		|| (nbr == 10 && str[0] != '-' && strnbr < 0)
		|| (nbr > 10 && str[0] != '-'))
		return (1);
	return (0);
}

int	check_dup(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i + 1])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_atoi(arr[i]) == ft_atoi(arr[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	checkarr(char **arr)
{
	int	i;
	int	pos;

	i = 0;
	while (arr[i])
	{
		pos = 0;
		if (arr[i][pos] == '-' || arr[i][pos] == '+')
		{
			pos++;
			if (arr[i][pos] < '0' || arr[i][pos] > '9')
				return (1);
		}
		while (arr[i][pos])
		{
			if (arr[i][pos] < '0' || arr[i][pos] > '9')
				return (1);
			pos++;
		}
		if (check_max_min(arr[i]))
			return (1);
		i++;
	}
	return (0);
}

void	checksizearr(int argc, char **argv, int *size, t_chunk data)
{
	int	i;

	i = 1;
	if (argc == 1)
		exit(0);
	while (argv[i])
	{
		*size += count_nbr(argv[i], ' ');
		i++;
	}
	i = 1;
	while (i < argc)
	{
		if (!(ft_strncmp(argv[i], "", sizeof(argv[i]))))
			error(data.arr, data.a, data.b);
		else if (only_space(argv[i]))
			error(data.arr, data.a, data.b);
		i++;
	}
}
