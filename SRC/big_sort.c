/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   big_sort.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/25 15:15:41 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/03 17:37:09 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	maxpass_loop(t_node **stack_a, t_node **stack_b, int argc, int max_bits)
{
	radix_sort(stack_a, stack_b, argc, max_bits);
	while (*stack_b != NULL)
		action_pa(stack_a, stack_b);
}

int	find_maxdivide(t_node *head)
{
	int i;
	int	max;
	int	max_bits;

	i = 1;
	max_bits = 0;
	max = head->tag;
	while (head != NULL)
	{
		if (head->tag > max)
			max = head->tag;
		head = head->next;
	}
	while (i <= 32)
	{
		if (max >> i)
			max_bits++;
		i++;
	}
	return (max_bits);
}

void	radix_sort(t_node **stack_a, t_node **stack_b, int max_numbers, int max_bits)
{
	int	digit;
	int	count;

	digit = 0;
	count = 0;
	while (digit < max_bits)
	{
		while (count < max_numbers)
		{
			if ((*stack_a)->tag >> digit & 1)
				action_pb(stack_a, stack_b);
			else
				action_ra(stack_a);
			count++;
		}
		if (count == max_numbers)
		{
			while (*stack_b != NULL)
				action_pa(stack_a, stack_b);
			count = 0;
		}
		digit++;
	}
}
