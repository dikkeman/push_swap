/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm_sa.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 20:43:06 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/10/19 21:22:24 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_sa(void)
{
	write(1, "sa", 2);
	write(1, "\n", 2);
}

void	action_sa(t_node **head)
{
	int		first;
	int		second;

	first = (*head)->value;
	second = (*head)->next->value;
	(*head)->value = second;
	(*head)->next->value = first;
	print_sa();
	print_list(*head);
}
