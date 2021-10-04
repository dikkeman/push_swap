/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm_r.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/22 12:04:20 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/10/04 18:56:06 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_rra(void)
{
	write(1, "rra", 3);
	write(1, "\n", 2);
}

void	action_rra(void)
{
	struct s_node	*last;
	struct s_node	*second_last;

	last = t_main.stack_a;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = t_main.stack_a;
	t_main.stack_a = last;
	write(1, "\n", 2);
	print_rra();
	print_list(t_main.stack_a);
}
