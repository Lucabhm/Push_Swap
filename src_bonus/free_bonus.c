/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:23:39 by lbohm             #+#    #+#             */
/*   Updated: 2024/01/19 23:18:13 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/checker_bonus.h"

void	freelst_b(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}

void	error_bonus(char *str, t_chunk data, char **opall)
{
	ft_putstr_fd("Error\n", 2);
	freerest(data.arr, data.a, data.b);
	free(opall);
	free(str);
	exit(0);
}

void	check_input(char *str, t_chunk data, char **opall)
{
	int	i;

	i = 0;
	while (opall[i])
	{
		if (!(ft_strncmp(str, opall[i], ft_strlen(str))))
			break ;
		i++;
	}
	if (!(opall[i]))
		error_bonus(str, data, opall);
}