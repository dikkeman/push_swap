/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 14:22:19 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/03 11:53:43 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_nonvalid(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j + 1]) == 0 && argv[i][j] == '-')
				return (true);
			if (ft_isdigit(argv[i][j]) == 0 && argv[i][j] != '-')
				return (true);
			j++;
		}
		j = 0;
		i++;
	}
	return (false);
}

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
				return (true);
			counter++;
		}
		i++;
		counter = i + 1;
	}
	return (false);
}

/*	
	Invalid inputs:
	- Duplicate numbers
	- Some arguments aren’t integers
	- No input
	- MAX_INT + 1 or MIN_INT - 1
*/

int	check_errors(int *data, int argc, char **argv)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	if (argc < 2)
		error = true;
	while (i < argc - 1)
	{
		if (ft_atol(argv[i + 1]) != data[i])
			error = true;
		i++;
	}
	if (check_duplicates(data, argc) == true)
		error = true;
	if (check_nonvalid(argc, argv) == true)
		error = true;
	if (error == true)
	{	
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	algorithm_check(t_node **stack_a, t_node **stack_b, int argc)
{
	int	malloc_check;

	malloc_check = 0;
	if (argc == 3)
		algorithm_two(stack_a);
	else if (argc == 4)
		algorithm_three_a(stack_a);
	else if (argc <= 6 && argc >= 5)
		algorithm_five(stack_a, stack_b, argc);
	else if (argc > 6)
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
	}
	if (check_errors(data, argc, argv) == 0)
		error = algorithm_check(&stack_a, &stack_b, argc);
	if (error == -1)
		return (-1);
	return (0);
}
