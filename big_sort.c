/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   big_sort.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/25 15:15:41 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/11/28 17:24:29 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_sort(t_node **stack_a, t_node **stack_b, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if ((*stack_a)->tag == i)
		{
			action_pb(stack_a, stack_b);
			i++;
		}
		else
			action_ra(stack_a);
	}
	while (i > 0)
	{
		action_pa(stack_a, stack_b);
		i--;
	}
}
