/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/02 13:55:49 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/06 20:22:28 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

/*
	0 = false
	1 = true
*/

typedef struct s_node {
	int				value;
	int				tag;
	struct s_node	*next;
}					t_node;

typedef struct s_tree {
	t_node			*list;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

/*
	SORT ALGORITHM
*/

void	algorithm_two(t_node **head);

void	algorithm_three(t_node **head);

void	algorithm_five(t_node **stack_a, t_node **stack_b, int argc);

int		algorithm_radix(t_node **stack_a, t_node **stack_b, int argc);

void	radix_sort(t_node **stack_a, t_node **stack_b \
			, int max_numbers, int max_bits);

int		find_maxbits(t_node *head);

/*
	LIBFT
*/

int		ft_atoi(const char *str);

long	ft_atol(const char *str);

int		ft_isdigit(int input);

void	*ft_calloc(size_t nitems, size_t n);

void	ft_bzero(void *str, size_t n);

/*
	PUSH SWAP
*/

void	action_sa(t_node **head);

void	action_ra(t_node **head);

void	action_rra(t_node **head);

void	action_rb(t_node **head);

void	action_rrb(t_node **head);

void	action_pa(t_node **stack_a, t_node **stack_b);

void	action_pb(t_node **stack_a, t_node **stack_b);

/*
	LISTS
*/

void	new_node(t_node **head, int number, int tag);

int		ft_issorted(t_node *head);

int		tree_sort(t_node **stack_a);

int		find_min(t_node *stack_a);

#endif
