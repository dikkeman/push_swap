/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 14:22:19 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/16 19:40:38 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_errno(int *data, t_node *stack_a)
{
	free(data);
	free(stack_a);
	return (-1);
}

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
	int		*data;
	t_node	*stack_a;
	t_node	*stack_b;

	i = 1;
	error = 0;
	data = ft_calloc(sizeof(int) * (argc - 1), 1);
	if (!data)
		return (-1);
	while (i < argc)
	{
		new_node(&stack_a, ft_atoi(argv[i]), 0);
		data[i - 1] = ft_atoi(argv[i]);
		i++;
		if (stack_a == NULL)
			return (free_errno(data, stack_a));
	}
	if (check_errors(data, argc, argv) == 0)
		error = algorithm_check(&stack_a, &stack_b, argc);
	if (error == -1)
		return (free_errno(data, stack_a));
	return (0);
}
