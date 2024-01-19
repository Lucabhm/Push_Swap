/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:06:19 by lucabohn          #+#    #+#             */
/*   Updated: 2024/01/19 12:01:37 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_a(t_list **a, int check)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (*a)
	{
		first = *a;
		if (first->next)
		{
			second = first->next;
			last = ft_lstlast(first);
			last->next = first;
			first->next = NULL;
			*a = second;
		}
	}
	if (check == 1)
		ft_printf("ra\n");
}

void	rotate_b(t_list **b, int check)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (*b)
	{
		first = *b;
		if (first->next)
		{
			second = first->next;
			last = ft_lstlast(first);
			last->next = first;
			first->next = NULL;
			*b = second;
		}
	}
	if (check == 1)
		ft_printf("rb\n");
}

void	swap_a(t_list **a, int check)
{
	t_list	*first;
	t_list	*second;

	if (*a)
	{
		first = *a;
		if (first->next)
		{
			second = first->next;
			first->next = second->next;
			second->next = first;
			*a = second;
		}
	}
	if (check == 1)
		ft_printf("sa\n");
}

void	swap_b(t_list **b, int check)
{
	t_list	*first;
	t_list	*second;

	if (*b)
	{
		first = *b;
		if (first->next)
		{
			second = first->next;
			first->next = second->next;
			second->next = first;
			*b = second;
		}
	}
	if (check == 1)
		ft_printf("sb\n");
}
