/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:37:42 by lbohm             #+#    #+#             */
/*   Updated: 2024/01/18 16:45:23 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	freearr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	freeall(char **arr, char **arg)
{
	freearr(arr);
	freearr(arg);
}

void	freerest(char **arr, t_list **a, t_list **b)
{
	if (a)
		freelst(a);
	if (b)
		freelst(b);
	if (arr)
		freearr(arr);
}

void	freelst(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	free(lst);
}
