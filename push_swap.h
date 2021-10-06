/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 14:19:41 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/10/06 20:48:54 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_node {
	int				value;
	struct	s_node	*next;
}					t_node;

struct			s_main {
	t_node		*stack_a;
}				t_main;

/*
	LIBFT
*/

int	ft_atoi(const char *str);

/*
	PUSH SWAP
*/

void action_sa(t_node **head);

/*
	LISTS
*/

void print_list(t_node *head);

void new_node(t_node **head, int number);

#endif