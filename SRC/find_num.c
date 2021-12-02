/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_num.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/02 13:45:33 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/02 13:53:44 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min(t_node *stack_a)
{
	int	min_number;

	min_number = stack_a->value;
	while (stack_a != NULL)
	{
		if (min_number > stack_a->value)
			min_number = stack_a->value;
		stack_a = stack_a->next;
	}
	return (min_number);
}

int	find_sec_min(t_node *stack_a)
{
	int	min_number;
	int	sec_min_num;

	min_number = stack_a->value;
	sec_min_num = stack_a->value;
	while (stack_a != NULL)
	{
		if (min_number > stack_a->value)
			min_number = stack_a->value;
		else if (sec_min_num > stack_a->value || sec_min_num == min_number)
			sec_min_num = stack_a->value;
		stack_a = stack_a->next;
	}
	return (sec_min_num);
}
