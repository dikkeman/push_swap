/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   big_sort.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/25 15:15:41 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/11/30 17:27:13 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	maxpass_loop(t_node **stack_a, t_node **stack_b, int argc, int max_pass)
{
	int	divide;

	divide = 1;
	while (max_pass > 0)
	{
		if (*stack_a != NULL)
			radix_sort_a(stack_a, stack_b, argc, divide);
		else if (*stack_b != NULL)
			radix_sort_b(stack_a, stack_b, argc, divide);
		divide = divide * 10;
		max_pass--;
	}
}

int	find_maxdivide(t_node *head)
{
	int	max;
	int	max_pass;

	max_pass = 0;
	max = head->tag;
	while (head != NULL)
	{
		if (head->tag > max)
			max = head->tag;
		head = head->next;
	}
	while (max > 0)
	{
		max = max / 10;
		max_pass++;
	}
	return (max_pass);
}

void	radix_sort_a(t_node **stack_a, t_node **stack_b \
			, int max_numbers, int divide)
{
	int		digit;
	int		count;
	int		result;
	int		pushed_num;

	digit = 0;
	while (digit <= 9)
	{
		pushed_num = 0;
		count = 0;
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
		digit++;
	}
}

void	radix_sort_b(t_node **stack_a, t_node **stack_b \
			, int max_numbers, int divide)
{
	int		digit;
	int		count;
	int		result;
	int		pushed_num;

	digit = 9;
	while (digit >= 0)
	{
		pushed_num = 0;
		count = 0;
		while (count < max_numbers && *stack_b != NULL)
		{
			result = ((*stack_b)->tag / divide) % 10;
			if (result == digit)
			{
				action_pa(stack_a, stack_b);
				pushed_num++;
			}
			else
				action_rb(stack_b);
			count++;
		}
		max_numbers = max_numbers - pushed_num;
		digit--;
	}
}
