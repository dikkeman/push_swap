/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm_s.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 18:50:00 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/10/04 18:56:20 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Maybe make this file only for S commands. I wil have to take a look.
	RN it is not really clean.
 */

void	print_sa(void)
{
	write(1, "sa", 2);
	write(1, "\n", 2);
}

void	action_sa(void)
{
	int	first;
	int	second;

	first = t_main.stack_a->value;
	second = t_main.stack_a->next->value;
	t_main.stack_a->value = second;
	t_main.stack_a->next->value = first;
	write(1, "\n", 2);
	print_sa();
	print_list(t_main.stack_a);
}
