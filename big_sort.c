/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   big_sort.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/25 15:15:41 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/11/29 18:08:45 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_sort(t_node **stack_a, t_node **stack_b, int argc, int divide)
{
	int		digit;
	int		count;
	int		result;
	int		pushed_num;
	int		max_numbers;
	int		max_pass;

	digit = 0;
	max_numbers = argc;
	pushed_num = 0;
	count = 0;
	result = 0;
	max_pass = 1;
	while (digit <= 9)
	{
		while (count < max_numbers && *stack_a != NULL)
		{
			result = ((*stack_a)->tag / divide) % 10;
			if (result == digit)
			{
				action_pb(stack_a, stack_b);
				pushed_num++;
			}
			else
				action_ra(stack_a);
			count++;
		}
		max_numbers = max_numbers - pushed_num;
		pushed_num = 0;
		count = 0;
		digit++;
		if (max_pass > 0 && digit == 10)
		{
			digit = 0;
			max_pass--;
			max_numbers = argc;
			divide = divide * 10;
			while (*stack_b != NULL)
				action_pa(stack_a, stack_b);
		}
	}
	digit = argc;
	while (digit > 0)
	{
		action_pa(stack_a, stack_b);
		digit--;
	}
}
