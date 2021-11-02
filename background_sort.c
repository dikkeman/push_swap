/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   background_sort.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/26 11:06:09 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/11/02 16:01:57 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	background_pb(t_node **stack_a, t_node **stack_b)
{
	int		data;
	t_node	*temp;
	t_node	*new_list;

	data = (*stack_a)->value;
	new_list = NULL;
	new_node(stack_b, data);
	temp = (*stack_a)->next;
	*stack_a = temp;
}

void	background_ra(t_node **head)
{
	t_node	*temp;

	temp = (*head)->next;
	new_node(&temp, (*head)->value);
	*head = temp;
}

void	background_rra(t_node **head)
{
	t_node	*last;
	t_node	*temp;
	int		i;

	last = *head;
	i = 0;
	while (last->next != NULL)
	{
		last = last->next;
		i++;
	}
	temp = last;
	while (i > 0)
	{
		new_node(&temp, (*head)->value);
		*head = (*head)->next;
		i--;
	}
	*head = temp;
}
