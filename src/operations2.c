/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:15:33 by lucabohn          #+#    #+#             */
/*   Updated: 2024/01/16 14:25:29 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate_a(t_list **a, int check)
{
	t_list	*first;
	t_list	*secondlast;
	t_list	*last;

	first = *a;
	secondlast = *a;
	while (secondlast->next->next)
		secondlast = secondlast->next;
	last = ft_lstlast(first);
	last->next = first;
	secondlast->next = NULL;
	*a = last;
	if (check == 1)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_list **b, int check)
{
	t_list	*first;
	t_list	*secondlast;
	t_list	*last;

	first = *b;
	secondlast = *b;
	while (secondlast->next->next)
		secondlast = secondlast->next;
	last = ft_lstlast(first);
	last->next = first;
	secondlast->next = NULL;
	*b = last;
	if (check == 1)
		ft_printf("rrb\n");
}

void	push_a(t_list **a, t_list **b, int i)
{
	t_list	*push;
	t_list	*second;

	push = *b;
	if (push->next)
		second = push->next;
	else
		second = NULL;
	if (!(*a))
	{
		push->next = NULL;
		*a = push;
	}
	else
	{
		push->next = *a;
		*a = push;
	}
	*b = second;
	if (i == 1)
		ft_printf("pa\n");
}

void	push_b(t_list **a, t_list **b, int i)
{
	t_list	*push;
	t_list	*second;

	push = *a;
	second = push->next;
	if (!(*b))
	{
		push->next = NULL;
		*b = push;
	}
	else
	{
		push->next = *b;
		*b = push;
	}
	*a = second;
	if (i == 1)
		ft_printf("pb\n");
}
