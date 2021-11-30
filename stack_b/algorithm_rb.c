/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm_rb.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 19:45:58 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/11/30 14:38:18 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_rb(void)
{
	write(1, "rb", 2);
	write(1, "\n", 1);
}

void	action_rb(t_node **head)
{
	t_node	*temp;

	temp = (*head)->next;
	new_node(&temp, (*head)->value, (*head)->tag);
	*head = temp;
	print_rb();
}

void	print_rrb(void)
{
	write(1, "rrb", 3);
	write(1, "\n", 1);
}

void	action_rrb(t_node **head)
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
		new_node(&temp, (*head)->value, (*head)->tag);
		*head = (*head)->next;
		i--;
	}
	*head = temp;
	print_rrb();
}
