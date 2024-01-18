/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:03:40 by lbohm             #+#    #+#             */
/*   Updated: 2024/01/18 11:35:12 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**parsing(int argc, char **argv, t_chunk data)
{
	int		i;
	int		size;
	int		pos;
	char	**arr;
	char	**arg;

	i = 1;
	size = 0;
	pos = 0;
	checksizearr(argc, argv, &size, data);
	arr = (char **)malloc ((size + 1) * sizeof(char *));
	if (!(arr))
		error(arr, data.a, data.b);
	arr[size] = NULL;
	while (argc > i)
	{
		arg = ft_split(argv[i], ' ');
		if (!(arg))
			error(arr, data.a, data.b);
		sortarguments(arr, arg, &pos, data);
		i++;
	}
	if (checkarr(arr) || check_dup(arr))
		error(arr, data.a, data.b);
	return (arr);
}

void	sortarguments(char **arr, char **arg, int *pos, t_chunk data)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		arr[*pos] = ft_strdup(arg[i]);
		if (!(arr[*pos]))
		{
			freeall(arr, arg);
			error(arr, data.a, data.b);
		}
		(*pos)++;
		i++;
	}
	freearr(arg);
}

t_list	*fill_list(char **arr)
{
	t_list	*a;
	t_list	*new;
	int		*nbr;
	int		i;

	i = 0;
	a = NULL;
	new = NULL;
	while (arr[i])
	{
		nbr = (int *)malloc (sizeof(int));
		*nbr = ft_atoi(arr[i]);
		new = ft_lstnew(nbr);
		ft_lstadd_back(&a, new);
		i++;
	}
	return (a);
}

int	count_nbr(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
			if (s[i] == '\0')
				return (count);
		}
		i++;
	}
	return (count);
}

void	error(char **arr, t_list **a, t_list **b)
{
	ft_putstr_fd("Error", 2);
	ft_putstr_fd("\n", 2);
	freerest(arr, a, b);
	exit (0);
}
