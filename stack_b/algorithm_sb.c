/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm_sb.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 20:43:06 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/10/21 14:27:40 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_sb(void)
{
	write(1, "sb", 2);
	write(1, "\n", 2);
}

void	action_sb(t_node **head)
{
	int		first;
	int		second;

	first = (*head)->value;
	second = (*head)->next->value;
	(*head)->value = second;
	(*head)->next->value = first;
	print_sb();
	print_list(*head);
}
