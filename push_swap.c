/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 14:22:19 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/10/05 16:07:16 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algoritm_3numbers(void)
{
	if (t_main.stack_a->value > t_main.stack_a->next->next->value)
		action_ra();
	// if (t_main.stack_a->value > t_main.stack_a->next->value)
	// 	action_sa();
	// if (t_main.stack_a->value > t_main.stack_a->next->next->value)
	// 	action_rra();
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc <= 2)
	{
		write(1, "ERROR! I need some numbers!\n", 29);
		exit (0);
	}
	else
	{
		while (i < argc)
		{
			create_s_node(&t_main.stack_a, ft_atoi(argv[i]));
			i++;
		}
		print_list(t_main.stack_a);
		if (argc <= 4)
			algoritm_3numbers();
	}
}
