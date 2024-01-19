/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucabohn <lucabohn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:37:14 by lbohm             #+#    #+#             */
/*   Updated: 2024/01/19 23:33:53 by lucabohn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../lib/libft/libft.h"
# include "../lib/printf/ft_printf.h"

// structs

typedef struct s_size
{
	int	biggest;
	int	smallest;
}				t_size;

typedef struct s_chunk
{
	char	**arr;
	t_list	**a;
	t_list	**b;
	t_size	sizea;
	t_size	sizeb;
	int		best_rotate;
	int		best_nbr;
	int		direction;
}				t_chunk;

// push_swap

void	sortthree(t_list **a, t_size sizea);
void	sort_rest(t_chunk data);
int		main(int argc, char **argv);
void	rotate_up(int rotate, int rotate2, t_chunk data);
void	rotate_down(int rotate, int rotate2, t_chunk data);

// operations

void	rotate_a(t_list **a, int check);
void	rotate_b(t_list **b, int check);
void	swap_a(t_list **a, int check);
void	swap_b(t_list **b, int check);

//operations2

void	reverse_rotate_a(t_list **a, int check);
void	reverse_rotate_b(t_list **b, int check);
void	push_a(t_list **a, t_list **b, int i);
void	push_b(t_list **a, t_list **b, int i);

// operations3

void	swap_a_and_b(t_list **a, t_list **b, int i);
void	rotate_a_and_b(t_list **a, t_list **b, int i);
void	reverse_rotate_a_and_b(t_list **a, t_list **b, int i);

// parsing

char	**parsing(int argc, char **argv, t_chunk data);
void	sortarguments(char **arr, char **arg, int *pos, t_chunk data);
t_list	*fill_list(char **arr);
int		count_nbr(char const *s, char c);
void	error(char **arr, t_list **a, t_list **b);

// checkerparsing

void	checksizearr(int argc, char **argv, int *size, t_chunk data);
int		checkarr(char **arr);
int		check_max_min(char *str);
int		check_dup(char **arr);
int		count_lst(t_list *first, t_list *second);

// helper

void	biggest_and_smallest(t_list **lst, t_size *size);
int		countstr(char **arr);
void	push_to_a(t_chunk data);
void	finish_sort_lst_a(t_chunk data);
int		only_space(char *str);

// free

void	freerest(char **arr, t_list **a, t_list **b);
void	freelst(t_list **lst);
void	freeall(char **arr, char **arg);
void	freearr(char **arr);

// check

int		sortedchecka(t_list **lst);
int		checksizea(t_list **lst, t_size sizea);
int		checkenda(t_list **lst, t_size *size);
int		check_first_and_lasta(t_list **a, t_size size);
void	check_best_rotate(t_chunk *data);

// best_rotate

int		best_rotate_lst_a(int nbr, t_list **a, t_chunk *data);
int		best_rotate_lst_b(int nbr, t_list **a, t_chunk *data);
int		best_rotate_to_a(int nbr, t_list **a, t_chunk *data);
int		find_best_rotate(int rotate, int rotate2, t_chunk *data, int *nbr);
void	lst_check(t_list *lst, int *nextnbr, int nbr, int sort);

#endif