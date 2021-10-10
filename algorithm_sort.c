/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/09 23:53:24 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/10/10 01:44:16 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm3(t_node **head)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = *head;
	while (temp != NULL)
	{
		t_main.data[i] = temp->value;
		temp = temp->next;
		i++;
	}
	if (t_main.data[0] > t_main.data[1] && t_main.data[1] > t_main.data[2] && t_main.data[2] < t_main.data[0])
	{
		action_sa(head);
		action_rra(head);
	}
	else if (t_main.data[1] < t_main.data[2] && t_main.data[0] < t_main.data[2] && t_main.data[0] > t_main.data[1])
		action_sa(head);
	else if (t_main.data[0] < t_main.data[1] && t_main.data[0] > t_main.data[2] && t_main.data[1] > t_main.data[2])
		action_rra(head);
	else if (t_main.data[0] > t_main.data[1] && t_main.data[0] > t_main.data[2] && t_main.data[1] < t_main.data[2])
		action_ra(head);
	else if (t_main.data[0] < t_main.data[1] && t_main.data[1] > t_main.data[2] && t_main.data[0] < t_main.data[2])
	{
		action_sa(head);
		action_ra(head);
	}
}

void	algorithm5(int argc)
{
	int	i;

	i = 0;
	while (i < argc - 3)
	{
		action_pb();
		i++;
	}
	algorithm3(&t_main.stack_a);
	while (i > 0)
	{
		action_pa();
		algorithm3(&t_main.stack_a);
		i--;
	}
}
