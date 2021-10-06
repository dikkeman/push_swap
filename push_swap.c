/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 14:22:19 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/10/06 20:49:18 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void algorithm3(void)
{
	if (t_main.stack_a->value > t_main.stack_a->next->value)
		action_sa(&t_main.stack_a);
}

int	main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc <= 2)
	{
		write(1, "ERROR", 5);
		return (0);
	}
	while (i < argc)
	{
		new_node(&t_main.stack_a, ft_atoi(argv[i]));
		i++;
	}
	algorithm3();
	return (0);
}
