/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm_p.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/30 17:16:54 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/01 14:34:57 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Careful noet linking it in the wrong way.
	Stack_a and Stack_b can easily be linked to eachother.
	The whole algorithm won't work if they are linked to eachother.

	action_pb() is the first time I will use it.
	That is why I use new_node for the first time
	and using ft_calloc() there.
*/

void	print_pa(void)
{
	write(1, "pa", 2);
	write(1, "\n", 1);
}

void	action_pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	temp = (*stack_b);
	*stack_b = (*stack_b)->next;
	if (*stack_a == NULL)
	{
		temp->next = NULL;
		*stack_a = temp;
	}
	else
	{
		temp->next = *stack_a;
		*stack_a = temp;
	}
	print_pa();
}

void	print_pb(void)
{
	write(1, "pb", 2);
	write(1, "\n", 1);
}

void	action_pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	temp = (*stack_a);
	*stack_a = (*stack_a)->next;
	if (*stack_b == NULL)
	{
		temp->next = NULL;
		*stack_b = temp;
	}
	else
	{
		temp->next = *stack_b;
		*stack_b = temp;
	}
	print_pb();
}
