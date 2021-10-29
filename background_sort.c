/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   background_sort.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/26 11:06:09 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/10/29 14:58:12 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	background_pa(t_node **stack_a, t_node **stack_b)
{
	int		data;
	t_node	*temp;
	t_node	*new_list;

	new_list = malloc(sizeof(t_node));
	data = (*stack_b)->value;
	temp = (*stack_b)->next;
	new_list->value = data;
	new_list->next = *stack_a;
	*stack_a = new_list;
	temp = (*stack_b)->next;
}

void	background_pb(t_node **stack_a, t_node **stack_b)
{
	int		data;
	t_node	*temp;
	t_node	*new_list;

	data = (*stack_a)->value;
	new_list = NULL;
	if (*stack_b == NULL)
		new_node(stack_b, data);
	else
	{
		new_node(&new_list, data);
		new_list->next = *stack_b;
		*stack_b = new_list;
	}
	temp = (*stack_a)->next;
	*stack_a = temp;
	printf("A:\n");
	print_list(*stack_a);
	printf("B:\n");
	print_list(*stack_b);
}

void	background_ra(t_node **head)
{
	t_node	*temp;

	temp = (*head)->next;
	new_node(&temp, (*head)->value);
	*head = temp;
}
