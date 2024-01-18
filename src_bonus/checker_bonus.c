/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:27:10 by lbohm             #+#    #+#             */
/*   Updated: 2024/01/18 13:55:13 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/checker_bonus.h"

int	main(int argc, char **argv)
{
	t_chunk	data;
	char	*str;

	data.a = NULL;
	data.b = NULL;
	data.arr = NULL;
	str = "";
	data.arr = parsing(argc, argv, data);
	if (countstr(data.arr) > 1)
	{
		data.a = (t_list **)malloc (countstr(data.arr) * sizeof(t_list));
		if (!(data.a))
			error(data.arr, data.a, data.b);
		data.b = (t_list **)malloc (countstr(data.arr) * sizeof(t_list));
		if (!(data.b))
			error(data.arr, data.a, data.b);
		*data.b = NULL;
		*data.a = fill_list(data.arr);
		read_input(str, data);
		if (sortedchecka(data.a) == countstr(data.arr))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	freerest(data.arr, data.a, data.b);
	return (0);
}

void	check_operation(t_list **op, t_list **a, t_list **b)
{
	char	*opall[12];

	opall[0] = "sa\n";
	opall[1] = "sb\n";
	opall[2] = "pa\n";
	opall[3] = "pb\n";
	opall[4] = "ra\n";
	opall[5] = "rb\n";
	opall[6] = "rra\n";
	opall[7] = "rrb\n";
	opall[8] = "rr\n";
	opall[9] = "rrr\n";
	opall[10] = "ss\n";
	opall[11] = NULL;
	check_operation_2(op, a, b, opall);
}

void	check_operation_2(t_list **op, t_list **a, t_list **b, char **opall)
{
	int		i;
	t_list	*lst;
	char	*str;

	lst = *op;
	while (lst)
	{
		str = lst->content;
		i = 0;
		while (opall[i])
		{
			if (!(ft_strncmp(str, opall[i], sizeof(str))))
			{
				if (!(operation_b(i, a, b)))
					break ;
			}
			i++;
		}
		lst = lst->next;
	}
}

int	operation_b(int i, t_list **a, t_list **b)
{
	if (i == 0 && *a)
		swap_a(a, 2);
	else if (i == 1 && *b)
		swap_b(b, 2);
	else if (i == 2 && *b)
		push_a(a, b, 2);
	else if (i == 3 && *a)
		push_b(a, b, 2);
	else if (i == 4 && *a)
		rotate_a(a, 2);
	else if (i == 5 && *b)
		rotate_b(b, 2);
	else if (i == 6 && *a)
		reverse_rotate_a(a, 2);
	else if (i == 7 && *b)
		reverse_rotate_b(b, 2);
	else if (i == 8 && *a && *b)
		rotate_a_and_b(a, b, 2);
	else if (i == 9 && *a && *b)
		reverse_rotate_a_and_b(a, b, 2);
	else if (i == 10 && *a && *b)
		swap_a_and_b(a, b, 2);
	else
		return (1);
	return (0);
}

void	read_input(char *str, t_chunk data)
{
	t_list	*operations;
	t_list	*newnode;

	operations = NULL;
	while (str)
	{
		str = get_next_line(0);
		if (!(str))
			break ;
		newnode = ft_lstnew(str);
		ft_lstadd_back(&operations, newnode);
	}
	free(str);
	check_operation(&operations, data.a, data.b);
	freelst_b(&operations);
}
