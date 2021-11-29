/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm_p.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/09 23:45:50 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/11/29 13:43:08 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Careful noet linking it in the wrong way.
	Stack_a and Stack_b can easily be linked to eachother.
	The whole algorithm won't work if they are linked to eachother.

	action_pb() is the first time I will use it.
	That is why I use new_node for the first time
	and using malloc() there.
*/

void	print_pa(void)
{
	write(1, "pa", 2);
	write(1, "\n", 1);
}

void	action_pa(t_node **stack_a, t_node **stack_b)
{
	int		value;
	int		tag;
	t_node	*temp;
	t_node	*new_list;

	new_list = malloc(sizeof(t_node));
	value = (*stack_b)->value;
	tag = (*stack_b)->tag;
	temp = (*stack_b)->next;
	new_list->value = value;
	new_list->tag = tag;
	new_list->next = *stack_a;
	*stack_a = new_list;
	temp = (*stack_b)->next;
	(*stack_b) = temp;
	print_pa();
}

void	print_pb(void)
{
	write(1, "pb", 2);
	write(1, "\n", 1);
}

void	action_pb(t_node **stack_a, t_node **stack_b)
{
	int		value;
	int		tag;
	t_node	*temp;
	t_node	*new_list;

	new_list = malloc(sizeof(t_node));
	value = (*stack_a)->value;
	tag = (*stack_a)->tag;
	temp = (*stack_a)->next;
	new_list->value = value;
	new_list->tag = tag;
	new_list->next = *stack_b;
	*stack_b = new_list;
	temp = (*stack_a)->next;
	(*stack_a) = temp;
	print_pb();
}
