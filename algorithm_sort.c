/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/09 23:53:24 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/10/19 21:30:02 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm3_a(t_node **head)
{
	if ((*head)->value > (*head)->next->value && (*head)->next->value > (*head)->next->next->value && (*head)->next->next->value < (*head)->value)
	{
		action_sa(head);
		action_rra(head);
	}
	else if ((*head)->next->value < (*head)->next->next->value && (*head)->value < (*head)->next->next->value && (*head)->value > (*head)->next->value)
		action_sa(head);
	else if ((*head)->value < (*head)->next->value && (*head)->value > (*head)->next->next->value && (*head)->next->value > (*head)->next->next->value)
		action_rra(head);
	else if ((*head)->value > (*head)->next->value && (*head)->value > (*head)->next->next->value && (*head)->next->value < (*head)->next->next->value)
		action_ra(head);
	else if ((*head)->value < (*head)->next->value && (*head)->next->value > (*head)->next->next->value && (*head)->value < (*head)->next->next->value)
	{
		action_sa(head);
		action_ra(head);
	}
}

void	algorithm3_b(t_node **head)
{
	if ((*head)->value > (*head)->next->value && (*head)->next->value > (*head)->next->next->value && (*head)->next->next->value < (*head)->value)
	{
		action_sb(head);
		action_rrb(head);
	}
	else if ((*head)->next->value < (*head)->next->next->value && (*head)->value < (*head)->next->next->value && (*head)->value > (*head)->next->value)
		action_sb(head);
	else if ((*head)->value < (*head)->next->value && (*head)->value > (*head)->next->next->value && (*head)->next->value > (*head)->next->next->value)
		action_rrb(head);
	else if ((*head)->value > (*head)->next->value && (*head)->value > (*head)->next->next->value && (*head)->next->value < (*head)->next->next->value)
		action_rb(head);
	else if ((*head)->value < (*head)->next->value && (*head)->next->value > (*head)->next->next->value && (*head)->value < (*head)->next->next->value)
	{
		action_sb(head);
		action_rb(head);
	}
}

int		count_difference(int first, int last, int main)
{
	int	counter_first;
	int	counter_last;

	counter_first = 0;
	counter_last = 0;
	while (first <= main)
	{
		first++;
		counter_first++;
	}
	while (last >= main)
	{
		last--;
		counter_last++;
	}
	if (counter_first < counter_last)
		return (2);
	else if (counter_first > counter_last)
		return (1);
	else
		return (0);
}

/*
	ALGORITHM 5
	---
	I will mainly use algorithm3() to sort 5 numbers,
	but I will push some numbers to stack_b.

	The first "while-loop" uses i as index and argc as limit.
	Because "argc" is a total of all inputs. I put -3 to assure
	that only 3 numbers will remain in stack_a.

	t_node temp will go to the last number BEFORE the second "while-loop".
*/

void	algorithm5(t_node **stack_a, t_node **stack_b, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 3)
	{
		action_pb(stack_a, stack_b);
		i++;
	}
	algorithm3_a(stack_a);
	while (i > 0)
	{
		action_pa(stack_a, stack_b);
		algorithm3_a(stack_a);
		i--;
	}
	action_pb(stack_a, stack_b);
	action_pb(stack_a, stack_b);
	algorithm3_a(stack_a);
	action_pa(stack_a, stack_b);
	action_pa(stack_a, stack_b);
}
