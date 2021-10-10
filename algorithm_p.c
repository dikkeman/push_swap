/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm_p.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/09 23:45:50 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/10/10 02:27:51 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_pa(void)
{
	write(1, "pa", 2);
	write(1, "\n", 2);
}

void	action_pa(void)
{
	t_node	*temp;
	t_node	*new_list;

	new_list = malloc(sizeof(t_node));
	new_list->value = t_main.stack_b->value;
	new_list->next = t_main.stack_a;
	t_main.stack_a = new_list;
	temp = t_main.stack_b->next;
	t_main.stack_b = temp;
	free(new_list);
	print_pa();
	print_list(t_main.stack_a);
}

void	print_pb(void)
{
	write(1, "pb", 2);
	write(1, "\n", 2);
}

void	action_pb(void)
{
	t_node	*temp;
	t_node	*new_list;

	new_list = malloc(sizeof(t_node));
	new_list->value = t_main.stack_a->value;
	new_list->next = t_main.stack_b;
	t_main.stack_b = new_list;
	temp = t_main.stack_a->next;
	t_main.stack_a = temp;
	free(new_list);
	print_pb();
	print_list(t_main.stack_b);
}
