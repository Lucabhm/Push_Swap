/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:47:12 by lbohm             #+#    #+#             */
/*   Updated: 2024/01/16 10:32:57 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_best_rotate(int rotate, int rotate2, t_chunk *data, int *nbr)
{
	rotate = best_rotate_lst_a(*nbr, data->a, data);
	rotate *= data->direction;
	rotate2 = best_rotate_lst_b(*nbr, data->b, data);
	rotate2 *= data->direction;
	if ((rotate < 0 && rotate2 < 0) || (rotate >= 0 && rotate2 >= 0))
	{
		if (rotate < 0)
		{
			if (rotate > rotate2)
				rotate = rotate2;
			rotate *= -1;
		}
		else
			if (rotate < rotate2)
				rotate = rotate2;
	}
	else
	{
		if (rotate < rotate2)
			rotate = (rotate * -1) + rotate2;
		else
			rotate = rotate + (rotate2 * -1);
	}
	return (rotate);
}

int	best_rotate_lst_a(int nbr, t_list **a, t_chunk *data)
{
	t_list	*lst;
	int		*lstnbr;
	int		i;

	lst = *a;
	i = 0;
	data->direction = 1;
	while (lst)
	{
		lstnbr = lst->content;
		if (nbr == *lstnbr)
			break ;
		i++;
		lst = lst->next;
	}
	if (i > ft_lstsize(*a) / 2)
	{
		data->direction = -1;
		return (ft_lstsize(*a) - i);
	}
	else
		return (i);
}

int	best_rotate_lst_b(int nbr, t_list **a, t_chunk *data)
{
	int		rotate;
	t_list	*lst;
	int		sort;
	int		nextnbr;

	rotate = 0;
	sort = 1;
	lst = *a;
	biggest_and_smallest(a, &data->sizeb);
	if (nbr > data->sizeb.biggest)
		rotate = best_rotate_lst_a(data->sizeb.biggest, a, data);
	else
	{
		nextnbr = -2147483648;
		if (nbr < data->sizeb.smallest)
			nextnbr = data->sizeb.biggest;
		else
			lst_check(lst, &nextnbr, nbr, sort);
		rotate = best_rotate_lst_a(nextnbr, a, data);
	}
	return (rotate);
}

int	best_rotate_to_a(int nbr, t_list **a, t_chunk *data)
{
	int		rotate;
	t_list	*lst;
	int		sort;
	int		nextnbr;

	rotate = 0;
	sort = 0;
	lst = *a;
	biggest_and_smallest(a, &data->sizeb);
	if (nbr > data->sizeb.biggest)
		rotate = best_rotate_lst_a(data->sizeb.smallest, a, data);
	else
	{
		nextnbr = 2147483647;
		if (nbr < data->sizeb.smallest)
			nextnbr = data->sizeb.smallest;
		else
			lst_check(lst, &nextnbr, nbr, sort);
		rotate = best_rotate_lst_a(nextnbr, a, data);
	}
	return (rotate);
}

void	lst_check(t_list *lst, int *nextnbr, int nbr, int sort)
{
	int	*lstnbr;

	lstnbr = NULL;
	while (lst)
	{
		lstnbr = lst->content;
		if (*lstnbr > nbr && *lstnbr < *nextnbr && sort == 0)
			*nextnbr = *lstnbr;
		if (*lstnbr < nbr && *lstnbr > *nextnbr && sort == 1)
			*nextnbr = *lstnbr;
		lst = lst->next;
	}
}
