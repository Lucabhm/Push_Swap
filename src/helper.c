/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:44:44 by lbohm             #+#    #+#             */
/*   Updated: 2024/01/18 11:59:07 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	biggest_and_smallest(t_list **lst, t_size *size)
{
	t_list	*first;
	t_list	*second;
	int		*firstnbr;
	int		*secondnbr;

	first = *lst;
	size->biggest = 0;
	size->smallest = 0;
	if (first->next)
	{
		second = first->next;
		firstnbr = first->content;
		size->biggest = *firstnbr;
		size->smallest = *firstnbr;
		while (second)
		{
			secondnbr = second->content;
			if (size->biggest < *secondnbr)
				size->biggest = *secondnbr;
			if (size->smallest > *secondnbr)
				size->smallest = *secondnbr;
			second = second->next;
		}
	}
}

int	countstr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	push_to_a(t_chunk data)
{
	t_list	*lst;
	int		rotate;
	int		*lstnbr;

	lst = *data.a;
	while (*data.b)
	{
		lst = *data.b;
		lstnbr = lst->content;
		rotate = best_rotate_to_a(*lstnbr, data.a, &data);
		rotate *= data.direction;
		if (rotate < 0)
		{
			while (rotate++ != 0)
				reverse_rotate_a(data.a, 1);
		}
		else
		{
			while (rotate-- != 0)
				rotate_a(data.a, 1);
		}
		push_a(data.a, data.b, 1);
	}
}

void	finish_sort_lst_a(t_chunk data)
{
	int	rotate;

	biggest_and_smallest(data.a, &data.sizea);
	if (sortedchecka(data.a) != ft_lstsize(*data.a))
	{
		rotate = best_rotate_lst_a(data.sizea.smallest, data.a, &data);
		rotate *= data.direction;
		if (rotate < 0)
		{
			while (rotate++ != 0)
				reverse_rotate_a(data.a, 1);
		}
		else
		{
			while (rotate-- != 0)
				rotate_a(data.a, 1);
		}
	}
}

int	only_space(char *str)
{
	int	i;
	int	spaces;

	i = 0;
	spaces = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			spaces++;
		i++;
	}
	if (spaces == i)
		return (1);
	return (0);
}
