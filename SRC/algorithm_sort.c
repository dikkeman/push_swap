/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/09 23:53:24 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/02 13:53:44 by xvoorvaa      ########   odam.nl         */
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

void	algorithm_three_a(t_node **head)
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

void	algorithm_three_b(t_node **head)
{
	int	number1;
	int	number2;
	int	number3;

	number1 = (*head)->value;
	number2 = (*head)->next->value;
	number3 = (*head)->next->next->value;
	if (number1 > number2 && number2 > number3 && number3 < number1)
	{
		action_sb(head);
		action_rrb(head);
	}
	else if (number2 < number3 && number1 < number3 && number1 > number2)
		action_sb(head);
	else if (number1 < number2 && number1 > number3 && number2 > number3)
		action_rrb(head);
	else if (number1 > number2 && number1 > number3 && number2 < number3)
		action_rb(head);
	else if (number1 < number2 && number2 > number3 && number1 < number3)
	{
		action_sb(head);
		action_rb(head);
	}
}

/*
	ALGORITHM 5
	---
	I will first look for the minimum number
	and the second minimum number. Afterward I will push them to stack_b.
	Use algorithm_three and push all numbers back to stack_a.

*/

void	algorithm_five(t_node **stack_a, t_node **stack_b)
{
	int	min_number;
	int	sec_min_number;

	min_number = find_min(*stack_a);
	sec_min_number = find_sec_min(*stack_a);
	while (min_number != (*stack_a)->value)
		action_ra(stack_a);
	if (min_number == (*stack_a)->value)
		action_pb(stack_a, stack_b);
	while (sec_min_number != (*stack_a)->value)
		action_ra(stack_a);
	if (sec_min_number == (*stack_a)->value)
		action_pb(stack_a, stack_b);
	algorithm_three_a(stack_a);
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
	int	i;
	int	max_pass;
	int	max_numbers;
	int	malloc_protect;

	i = argc;
	max_numbers = argc;
	malloc_protect = tree_sort(stack_a);
	if (malloc_protect == -1)
		return (-1);
	max_pass = find_maxdivide(*stack_a);
	maxpass_loop(stack_a, stack_b, max_numbers, max_pass);
	if (*stack_a == NULL)
	{
		while (i > 0)
		{
			action_pa(stack_a, stack_b);
			i--;
		}
	}
	return (0);
}
