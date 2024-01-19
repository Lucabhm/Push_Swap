/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:15:33 by lucabohn          #+#    #+#             */
/*   Updated: 2024/01/19 23:42:54 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate_a(t_list **a, int check)
{
	t_list	*first;
	t_list	*secondlast;
	t_list	*last;

	if (*a)
	{
		first = *a;
		if (first->next)
		{
			secondlast = *a;
			while (secondlast->next->next)
				secondlast = secondlast->next;
			last = ft_lstlast(first);
			last->next = first;
			secondlast->next = NULL;
			*a = last;
		}
	}
	if (check == 1)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_list **b, int check)
{
	t_list	*first;
	t_list	*secondlast;
	t_list	*last;

	if (*b)
	{
		first = *b;
		if (first->next)
		{
			secondlast = *b;
			while (secondlast->next->next)
				secondlast = secondlast->next;
			last = ft_lstlast(first);
			last->next = first;
			secondlast->next = NULL;
			*b = last;
		}
	}
	if (check == 1)
		ft_printf("rrb\n");
}

void	push_a(t_list **a, t_list **b, int i)
{
	t_list	*push;
	t_list	*second;

	if (*b)
	{
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
	}
	if (i == 1)
		ft_printf("pa\n");
}

void	push_b(t_list **a, t_list **b, int i)
{
	t_list	*push;
	t_list	*second;

	if (*a)
	{
		push = *a;
		if (push->next)
			second = push->next;
		else
			second = NULL;
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
	}
	if (i == 1)
		ft_printf("pb\n");
}
