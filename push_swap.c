/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 14:22:19 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/11/25 15:10:36 by xvoorvaa      ########   odam.nl         */
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
	if (argc <= 2)
	{
		write(1, "Error\n", 7);
		return (1);
	}
	if (check_duplicates(data, argc) == true)
	{
		write(1, "Error\n", 7);
		return (1);
	}
	if (check_nonvalid(argc, argv) == true)
	{
		write(1, "Error\n", 7);
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
	error = check_errors(data, argc, argv);
	if (argc == 3 && error == false)
		algorithm_two(&stack_a);
	else if (argc == 4 && error == false)
		algorithm_three_a(&stack_a);
	else if (argc <= 6 && argc >= 5 && error == false)
		algorithm_five(&stack_a, &stack_b, argc - 1);
	else if (argc > 6 && error == false)
		algorithm_radix(&stack_a, &stack_b, argc - 1);
	return (0);
}
