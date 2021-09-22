/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm_r.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/22 12:04:20 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/09/22 13:06:12 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	action_rra(void)
{
	int	temp;

	temp = t_main.stack_a[0];
	t_main.stack_a[0] = t_main.stack_a[1];
	t_main.stack_a[1] = temp;
	write(1, "sa", 2);
	write(1, "\n", 2);
}