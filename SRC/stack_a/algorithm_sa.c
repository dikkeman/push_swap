/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm_sa.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 20:43:06 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/03 22:15:10 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_sa(void)
{
	write(STDOUT_FILENO, "sa", 2);
	write(STDOUT_FILENO, "\n", 1);
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
}
