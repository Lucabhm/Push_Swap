/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:34:37 by lbohm             #+#    #+#             */
/*   Updated: 2024/01/19 23:19:09 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../include/push_swap.h"
# include "../lib/libft/libft.h"
# include "../lib/printf/ft_printf.h"
# include "../lib/get_next_line/get_next_line.h"

// checker_bonus

int		main(int argc, char **argv);
char	**check_operation(void);
int		operation_b(int i, t_list **a, t_list **b);
void	check_operation_2(t_list **op, t_list **a, t_list **b, char **opall);
void	read_input(char *str, t_chunk data);

// free_bonus

void	freelst_b(t_list **lst);
void	check_input(char *str, t_chunk data, char **opall);
void	error_bonus(char *str, t_chunk data, char **opall);

#endif