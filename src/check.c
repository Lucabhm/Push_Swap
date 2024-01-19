/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:42:53 by lbohm             #+#    #+#             */
/*   Updated: 2024/01/19 13:27:11 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sortedchecka(t_list **lst)
{
	t_list	*first;
	t_list	*second;
	int		i;

	i = 0;
	if (*lst)
	{
		first = *lst;
		if ((*lst)->next)
		{
			second = first->next;
			i = count_lst(first, second);
		}
	}
	else
		return (0);
	return (i + 1);
}

int	checksizea(t_list **lst, t_size sizea)
{
	t_list	*first;
	t_list	*second;
	int		*firstnbr;
	int		*secondnbr;

	first = *lst;
	if (first->next)
	{
		second = first->next;
		firstnbr = first->content;
		secondnbr = second->content;
		if ((*firstnbr > *secondnbr)
			|| (*firstnbr == sizea.smallest && *secondnbr == sizea.biggest))
			return (1);
	}
	return (0);
}

int	checkenda(t_list **lst, t_size *size)
{
	t_list	*first;
	t_list	*second;
	int		*firstnbr;
	int		*secondnbr;

	first = *lst;
	if (first->next)
	{
		second = first->next;
		firstnbr = first->content;
		secondnbr = second->content;
		if (*firstnbr == size->biggest && *secondnbr == size->smallest)
			return (1);
	}
	return (0);
}

int	check_first_and_lasta(t_list **a, t_size size)
{
	t_list	*first;
	t_list	*last;
	int		*firstnbr;
	int		*lastnbr;

	first = *a;
	last = ft_lstlast(first);
	firstnbr = first->content;
	lastnbr = last->content;
	if (*firstnbr > *lastnbr && *firstnbr != size.biggest)
		return (1);
	return (0);
}

void	check_best_rotate(t_chunk *data)
{
	t_list	*lst;
	int		rotate;
	int		rotate2;
	int		rotate3;
	int		*nbr;

	rotate = 0;
	rotate2 = 0;
	rotate3 = 0;
	lst = *data->a;
	nbr = lst->content;
	data->best_nbr = *nbr;
	rotate = find_best_rotate(rotate, rotate2, data, nbr);
	while (lst->next)
	{
		lst = lst->next;
		nbr = lst->content;
		rotate2 = find_best_rotate(rotate2, rotate3, data, nbr);
		if (rotate > rotate2)
		{
			data->best_nbr = *nbr;
			rotate = rotate2;
		}
	}
	data->best_rotate = rotate;
}
