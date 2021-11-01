/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 14:19:41 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/11/01 15:07:21 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*
	0 = FALSE
	1 = TRUE
*/

enum e_boolean
{
	FALSE = 0,
	TRUE = 1
};

typedef struct s_node {
	int				value;
	int				tag;
	struct s_node	*next;
}					t_node;

/*
	SORT ALGORITHM
*/

void	algorithm_two(t_node **head);

void	algorithm_three_a(t_node **head);

void	algorithm_three_b(t_node **head);

void	algorithm_five(t_node **stack_a, t_node **stack_b, int argc);

void	algorithm_radix(t_node **stack_a, t_node **stack_b, int argc);

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

void	background_pa(t_node **stack_a, t_node **stack_b);

void	background_pb(t_node **stack_a, t_node **stack_b);

void	background_ra(t_node **head);

void	background_rra(t_node **head);

/*
	LISTS
*/

void	print_list(t_node *head);

void	new_node(t_node **head, int number);

void	free_list(t_node *head);

int		sorting_check(t_node *head);

#endif