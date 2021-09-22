/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 14:19:41 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/09/22 18:27:18 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

struct	node	{
	int value;
	struct node* next;
	};

struct	s_main	{
	int	*stack_a;
	int	*stack_b;
}		t_main;

int		main(int argc, char **argv);

void	action_sa(void);

void	action_sb(void);

void	action_ss(void);

int		ft_atoi(const char *str);

void	*ft_calloc(size_t nitems, size_t n);

void	ft_bzero(void *str, size_t n);

//testing

void linkedlist(int argc);

#endif