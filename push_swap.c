/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 14:22:19 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/10/26 10:36:28 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(int *data, int argc)
{
	int	i;
	int	counter;

	i = 0;
	counter = 1;
	while (i < argc - 1)
	{
		while (counter < argc - 1)
		{
			if (data[i] - data[counter] == 0)
				return (1);
			counter++;
		}
		i++;
		counter = i + 1;
	}
	return (0);
}

/* Invalid input */

int	check_errors(int *data, int argc)
{
	if (argc <= 2)
	{
		write(1, "ERROR!\n", 8);
		return (1);
	}
	if (check_duplicates(data, argc) == 1)
	{
		write(1, "ERROR!\n", 8);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		error;
	int		*data;
	t_node	*stack_a;
	t_node	*stack_b;

	i = 1;
	data = malloc(sizeof(int) * (argc - 1));
	while (i < argc)
	{
		new_node(&stack_a, ft_atoi(argv[i]));
		data[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	error = check_errors(data, argc);
	if (argc == 3 && error == 0)
		algorithm_two(&stack_a);
	else if (argc == 4 && error == 0)
		algorithm_three_a(&stack_a);
	else if (argc <= 6 && argc >= 5 && error == 0)
		algorithm_five(&stack_a, &stack_b, argc - 1);
	else if(argc > 6 && error == 0)
	{
		algorithm_radix(&stack_a, &stack_b, argc - 1);
	}
	return (0);
}
