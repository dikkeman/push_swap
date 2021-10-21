/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm_ra.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 19:45:58 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/10/21 14:15:52 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_ra(void)
{
	write(1, "ra", 2);
	write(1, "\n", 2);
}

void	action_ra(t_node **head)
{
	t_node	*temp;

	temp = (*head)->next;
	new_node(&temp, (*head)->value);
	*head = temp;
	print_ra();
	print_list(*head);
}

void	print_rra(void)
{
	write(1, "rra", 3);
	write(1, "\n", 2);
}

void	action_rra(t_node **head)
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
	print_rra();
	print_list(temp);
}
