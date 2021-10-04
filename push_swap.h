/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 14:19:41 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/10/04 18:31:23 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

struct	s_node	{
	int				value;
	struct s_node	*next;
};

struct	s_main	{
	struct s_node	*stack_a;
	struct s_node	*stack_b;
}		t_main;

int		main(int argc, char **argv);

void	action_sa(void);

void	action_sb(void);

void	action_ss(void);

void	action_rra(void);

void	action_sa(void);

int		ft_atoi(const char *str);

void	*ft_calloc(size_t nitems, size_t n);

void	ft_bzero(void *str, size_t n);

//Lists

void	create_s_node(struct s_node **head, int number);

void	print_list(struct s_node *head);

#endif