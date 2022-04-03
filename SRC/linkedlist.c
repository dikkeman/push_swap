/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linkedlist.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 19:02:47 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/03 22:13:43 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_list(t_node **head)
{
	t_node	*temp;

	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	return (-1);
}

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

int	pathfinding(t_node *stack_a)
{
	int	i;
	int	min_number;

	i = 0;
	min_number = find_min(stack_a);
	while (min_number != stack_a->value)
	{
		stack_a = stack_a->next;
		i++;
	}
	if (i > 2)
		return (1);
	return (0);
}

int	ft_issorted(t_node *head)
{
	while (head->next != NULL)
	{
		if (head->value > head->next->value)
			return (false);
		head = head->next;
	}
	return (true);
}

void	new_node(t_node **head, int value, int tag)
{
	t_node	*new_node;
	t_node	*last_node;

	new_node = ft_calloc(sizeof(t_node), 1);
	if (!new_node)
	{
		free(new_node);
		return ;
	}
	last_node = *head;
	new_node->value = value;
	new_node->tag = tag;
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new_node;
	}
}
