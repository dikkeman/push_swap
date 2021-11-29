/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 14:19:41 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/11/29 13:39:51 by xvoorvaa      ########   odam.nl         */
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

void	algorithm_three_a(t_node **head);

void	algorithm_three_b(t_node **head);

void	algorithm_five(t_node **stack_a, t_node **stack_b, int argc);

void	algorithm_radix(t_node **stack_a, t_node **stack_b, int argc);

void	insert_sort(t_node **stack_a, t_node **stack_b, int argc, int divide);

/*
	LIBFT
*/

int		ft_atoi(const char *str);

int		ft_isdigit(int input);

/*
	PUSH SWAP
*/

void	action_sa(t_node **head);

void	action_ra(t_node **head);

void	action_rra(t_node **head);

void	action_sb(t_node **head);

void	action_rb(t_node **head);

void	action_rrb(t_node **head);

void	action_pa(t_node **stack_a, t_node **stack_b);

void	action_pb(t_node **stack_a, t_node **stack_b);

/*
	LISTS
*/

void	print_list(t_node *head);

void	new_node(t_node **head, int number);

void	free_list(t_node *head);

int		ft_issorted(t_node *head);

void	add_tag(t_node **head, int value, int tag);

void	print_tag(t_node *head);

void	copy_list(t_node **head, t_node *copy);

void	tree_sort(t_node **stack_a);

#endif
