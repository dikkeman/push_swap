/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/09 23:53:24 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/06 15:41:29 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	algorithm_two(t_node **head)
{
	if ((*head)->value > (*head)->next->value)
		action_sa(head);
}

/*
	Use a INT in the function to tell my program what stack it is.
	Is it stack_a or stack_b?
*/

void	algorithm_three(t_node **head)
{
	int	number1;
	int	number2;
	int	number3;

	number1 = (*head)->value;
	number2 = (*head)->next->value;
	number3 = (*head)->next->next->value;
	if (number1 > number2 && number2 > number3 && number3 < number1)
	{
		action_sa(head);
		action_rra(head);
	}
	else if (number2 < number3 && number1 < number3 && number1 > number2)
		action_sa(head);
	else if (number1 < number2 && number1 > number3 && number2 > number3)
		action_rra(head);
	else if (number1 > number2 && number1 > number3 && number2 < number3)
		action_ra(head);
	else if (number1 < number2 && number2 > number3 && number1 < number3)
	{
		action_sa(head);
		action_ra(head);
	}
}

/*
	ALGORITHM 5
	---
	I will first look for the minimum number
	and the second minimum number. Afterward I will push them to stack_b.
	Use algorithm_three and push all numbers back to stack_a.

*/

void	algorithm_five(t_node **stack_a, t_node **stack_b, int argc)
{
	int	min_number;
	int	sec_min_number;

	min_number = find_min(*stack_a);
	while (min_number != (*stack_a)->value)
		action_ra(stack_a);
	if (min_number == (*stack_a)->value)
		action_pb(stack_a, stack_b);
	if (argc > 5)
	{
		sec_min_number = find_sec_min(*stack_a);
		while (sec_min_number != (*stack_a)->value)
			action_ra(stack_a);
		if (sec_min_number == (*stack_a)->value)
			action_pb(stack_a, stack_b);
	}
	algorithm_three(stack_a);
	while (*stack_b != NULL)
		action_pa(stack_a, stack_b);
}

/*
	ALGORITHM MAX
	---

	The Radix sort won't be too difficult. I will pre sort with a tree system.
	Then I tag all numbers and sort it from lowest to highest.

	Treesort is the "pre-sort".
	Radix_sort is waar het allemaal om draait.
*/

int	algorithm_radix(t_node **stack_a, t_node **stack_b, int argc)
{
	int	max_bits;
	int	malloc_protect;

	malloc_protect = tree_sort(stack_a);
	if (malloc_protect == -1)
		return (-1);
	max_bits = find_maxbits(*stack_a);
	radix_sort(stack_a, stack_b, argc, max_bits);
	while (*stack_b != NULL)
		action_pa(stack_a, stack_b);
	return (0);
}
