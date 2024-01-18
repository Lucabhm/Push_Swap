/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:13:42 by lucabohn          #+#    #+#             */
/*   Updated: 2024/01/16 14:23:42 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_a_and_b(t_list **a, t_list **b, int i)
{
	swap_a(a, 2);
	swap_b(b, 2);
	if (i == 1)
		ft_printf("ss\n");
}

void	rotate_a_and_b(t_list **a, t_list **b, int i)
{
	rotate_a(a, 2);
	rotate_b(b, 2);
	if (i == 1)
		ft_printf("rr\n");
}

void	reverse_rotate_a_and_b(t_list **a, t_list **b, int i)
{
	reverse_rotate_a(a, 2);
	reverse_rotate_b(b, 2);
	if (i == 1)
		ft_printf("rrr\n");
}
