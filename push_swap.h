/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 14:19:41 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/10/11 19:35:32 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node {
	int				value;
	struct s_node	*next;
}					t_node;

/*
	SORT ALGORITHM
*/

void	algorithm3(t_node **head);

void	algorithm5(t_node **stack_a, t_node **stack_b, int argc);

/*
	LIBFT
*/

int		ft_atoi(const char *str);

/*
	PUSH SWAP
*/

void	action_sa(t_node **head);

void	action_ra(t_node **head);

void	action_rra(t_node **head);

void	action_pa(t_node **stack_a, t_node **stack_b);

void	action_pb(t_node **stack_a, t_node **stack_b);

/*
	LISTS
*/

void	print_list(t_node *head);

void	new_node(t_node **head, int number);

void	free_list(t_node *head);

#endif