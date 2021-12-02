/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm_ra.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 19:45:58 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/02 13:53:44 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	print_ra(void)
{
	write(1, "ra", 2);
	write(1, "\n", 1);
}

void	action_ra(t_node **head)
{
	t_node	*last;
	t_node	*first;

	last = *head;
	first = *head;
	while (last->next != NULL)
		last = last->next;
	*head = first->next;
	first->next = NULL;
	last->next = first;
	print_ra();
}

void	print_rra(void)
{
	write(1, "rra", 3);
	write(1, "\n", 1);
}

void	action_rra(t_node **head)
{
	t_node	*temp;
	t_node	*second_last;

	second_last = *head;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	temp = second_last->next;
	second_last->next = NULL;
	temp->next = *head;
	*head = temp;
	print_rra();
}
