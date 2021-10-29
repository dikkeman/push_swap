/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 14:22:19 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/10/29 16:14:52 by xvoorvaa      ########   odam.nl         */
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
				return (TRUE);
			counter++;
		}
		i++;
		counter = i + 1;
	}
	return (FALSE);
}

/*	Invalid inputs:
	- Duplicate numbers
	- Some arguments aren’t integers
	- No input
	- MAX_INT + 1 or MIN_INT - 1
*/

int	check_errors(int *data, int argc)
{
	int	i;

	i = 0;
	if (argc <= 2)
	{
		write(1, "ERROR!\n", 8);
		return (1);
	}
	if (check_duplicates(data, argc) == TRUE)
	{
		write(1, "ERROR!\n", 8);
		return (1);
	}
	while (ft_isdigit(data[i]) == TRUE)
		i++;
	if (ft_isdigit(data[i]) == FALSE)
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
	if (argc == 3 && error == FALSE)
		algorithm_two(&stack_a);
	else if (argc == 4 && error == FALSE)
		algorithm_three_a(&stack_a);
	else if (argc <= 6 && argc >= 5 && error == FALSE)
		algorithm_five(&stack_a, &stack_b, argc - 1);
	else if (argc > 6 && error == FALSE)
		algorithm_radix(&stack_a, &stack_b, argc - 1);
	return (0);
}
