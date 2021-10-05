/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm_r.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/22 12:04:20 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/10/05 16:50:41 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_rra(void)
{
	write(1, "rra", 3);
	write(1, "\n", 2);
}

void	action_rra(void)
{
	struct s_node	*first;
	struct s_node	*second_first;

	first = t_main.stack_a;
	second_first = NULL;
	while (first->next != NULL)
	{
		second_first = first;
		first = first->next;
	}
	second_first->next = NULL;
	first->next = t_main.stack_a;
	t_main.stack_a = first;
	write(1, "\n", 2);
	print_rra();
	print_list(t_main.stack_a);
}

void	print_ra(void)
{
	write(1, "ra", 3);
	write(1, "\n", 2);
}

void	action_ra(void)
{
	struct s_node	*first;
	struct s_node	*temp;

	first = t_main.stack_a;
	first = first->next;
	while (first->next != NULL)
	{
		temp = first;
		first = first->next;
	}
	first->next = t_main.stack_a;
	t_main.stack_a = first;
	printf("List in function: ");
	print_list(first);
	write(1, "\n", 2);
	print_ra();
	print_list(t_main.stack_a);
}