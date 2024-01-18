/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:36:44 by lbohm             #+#    #+#             */
/*   Updated: 2024/01/18 11:55:07 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_chunk	data;

	data.a = NULL;
	data.b = NULL;
	data.arr = NULL;
	data.arr = parsing(argc, argv, data);
	data.a = (t_list **)malloc (countstr(data.arr) * sizeof(t_list));
	if (!(data.a))
		error(data.arr, data.a, data.b);
	data.b = (t_list **)malloc (countstr(data.arr) * sizeof(t_list));
	if (!(data.b))
		error(data.arr, data.a, data.b);
	*data.b = NULL;
	*data.a = fill_list(data.arr);
	biggest_and_smallest(data.a, &data.sizea);
	while (sortedchecka(data.a) != countstr(data.arr))
	{
		if (countstr(data.arr) < 4)
			sortthree(data.a, data.sizea);
		else
			sort_rest(data);
	}
	freerest(data.arr, data.a, data.b);
	return (0);
}

void	sortthree(t_list **a, t_size sizea)
{
	while (sortedchecka(a) != ft_lstsize(*a))
	{
		if (checksizea(a, sizea) && !(checkenda(a, &sizea)))
			swap_a(a, 1);
		else
		{
			if (check_first_and_lasta(a, sizea))
				reverse_rotate_a(a, 1);
			else
				rotate_a(a, 1);
		}
	}
}

void	sort_rest(t_chunk data)
{
	int		rotate;
	int		rotate2;

	rotate = 0;
	rotate2 = 0;
	if (sortedchecka(data.a) != countstr(data.arr))
	{
		push_b(data.a, data.b, 1);
		push_b(data.a, data.b, 1);
		while (ft_lstsize(*data.a) > 3)
		{
			check_best_rotate(&data);
			rotate = best_rotate_lst_a(data.best_nbr, data.a, &data);
			rotate *= data.direction;
			rotate2 = best_rotate_lst_b(data.best_nbr, data.b, &data);
			rotate2 *= data.direction;
			rotate_up(rotate, rotate2, data);
			rotate_down(rotate, rotate2, data);
			push_b(data.a, data.b, 1);
		}
		biggest_and_smallest(data.a, &data.sizea);
		sortthree(data.a, data.sizea);
		push_to_a(data);
	}
	finish_sort_lst_a(data);
}

void	rotate_up(int rotate, int rotate2, t_chunk data)
{
	if (rotate > 0 || rotate2 > 0)
	{
		while (rotate > 0 && rotate2 > 0)
		{
			rotate_a_and_b(data.a, data.b, 1);
			rotate--;
			rotate2--;
		}
		while (rotate > 0)
		{
			rotate_a(data.a, 1);
			rotate--;
		}
		while (rotate2 > 0)
		{
			rotate_b(data.b, 1);
			rotate2--;
		}
	}
}

void	rotate_down(int rotate, int rotate2, t_chunk data)
{
	if (rotate < 0 || rotate2 < 0)
	{
		while (rotate < 0 && rotate2 < 0)
		{
			reverse_rotate_a_and_b(data.a, data.b, 1);
			rotate++;
			rotate2++;
		}
		while (rotate < 0)
		{
			reverse_rotate_a(data.a, 1);
			rotate++;
		}
		while (rotate2 < 0)
		{
			reverse_rotate_b(data.b, 1);
			rotate2++;
		}
	}
}
