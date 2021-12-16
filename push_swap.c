/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 14:22:19 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/16 22:41:03 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	algorithm_check(t_node **stack_a, t_node **stack_b, int argc)
{
	int	malloc_check;

	malloc_check = 0;
	if (argc == 3)
		algorithm_two(stack_a);
	else if (argc == 4)
		algorithm_three(stack_a);
	else if (argc <= 6 && argc >= 5 && ft_issorted(*stack_a) == false)
		algorithm_five(stack_a, stack_b, argc);
	else if (argc > 6 && ft_issorted(*stack_a) == false)
		malloc_check = algorithm_radix(stack_a, stack_b, argc - 1);
	return (malloc_check);
}

int	main(int argc, char **argv)
{
	int		i;
	int		error;
	t_node	*stack_a;
	t_node	*stack_b;

	i = 1;
	error = 0;
	while (i < argc)
	{
		new_node(&stack_a, ft_atoi(argv[i]), 0);
		if (!stack_a)
			return (free_list(&stack_a));
		i++;
	}
	if (check_errors(argc, argv) == 0)
		error = algorithm_check(&stack_a, &stack_b, argc);
	if (error == -1)
		return (free_list(&stack_a));
	return (0);
}
