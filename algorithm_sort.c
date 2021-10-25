/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/09 23:53:24 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/10/25 17:34:51 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	I will mainly use algorithm_three() to sort 5 numbers,
	but I will push some numbers to stack_b.

	The first "while-loop" uses i as index and argc as limit.
	Because "argc" is a total of all inputs. I put -3 to assure
	that only 3 numbers will remain in stack_a.

	t_node temp will go to the last number BEFORE the second "while-loop".
*/

void	algorithm_five(t_node **stack_a, t_node **stack_b, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 3)
	{
		action_pb(stack_a, stack_b);
		i++;
	}
	algorithm_three_a(stack_a);
	while (i > 0)
	{
		action_pa(stack_a, stack_b);
		algorithm_three_a(stack_a);
		i--;
	}
	i = 0;
	while (i < argc - 3)
	{
		action_pb(stack_a, stack_b);
		i++;
	}
	algorithm_three_a(stack_a);
	while (i > 0)
	{
		action_pa(stack_a, stack_b);
		algorithm_three_a(stack_a);
		i--;
	}
}

/*
	I will need to use Radix Sort, but I will not show it "On screen".
	It will be done in the background. Make a new list and use the "INT TAGS".
	Every number will be sorted and get a tag at the end from 0 - MAX OF ARGC.
	I will bring back every number to its original position with a tag on it.
	With these tags I will sort in stack_a & stack_b.

	EXAMPLE:
	VALUE -> 12 11 09 13 06
	TAGS  -> 03 02 01 04 00

*/

int *tag_sort(t_node **stack_a, int argc)
{
	printf("%d & %d", (*stack_a)->value, argc);
	return (0);
}

void	algorithm_radix(t_node **stack_a, t_node **stack_b, int argc)
{
	int *tags;
	
	tags = tag_sort(stack_a, argc);
	printf("%d & %d", (*stack_b)->value, argc);
}