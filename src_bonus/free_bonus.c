/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:23:39 by lbohm             #+#    #+#             */
/*   Updated: 2024/01/19 15:51:21 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/checker_bonus.h"

void	freelst_b(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}

void	error_bonus(t_list **a, t_list **b, char **arr, char **opall)
{
	ft_putstr_fd("Error\n", 2);
	freerest(arr, a, b);
	free(opall);
	exit(0);
}

void	check_input(char *str, char **opall, t_chunk data)
{
	int	i;

	i = 0;
	while (opall[i])
	{
		if (!(ft_strncmp(str, opall[i], ft_strlen(str))))
			break ;
		i++;
	}
	if (!(opall[i]))
	{
		free(str);
		error_bonus(data.a, data.b, data.arr, opall);
	}
}
