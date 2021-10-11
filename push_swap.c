/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 14:22:19 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/10/11 19:37:12 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(int *data, int argc)
{
	int	i;
	int counter;

	i = 0;
	counter = 1;
	while (i < argc - 1)
	{
		while (counter < argc - 1)
		{
			if (data[i] - data[counter] == 0)
			{			
				write(1, "ERROR!", 6);
				return (1);
			}
			counter++;
		}
		i++;
		counter = i + 1;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int 	error;
	int		*data;
	t_node	*stack_a;
	t_node	*stack_b;

	i = 1;
	error = 0;
	data = malloc(sizeof(int) * (argc - 1));
	if (argc <= 2)
	{
		write(1, "ERROR! Need more inputs", 5);
		return (0);
	}
	while (i < argc)
	{
		new_node(&stack_a, ft_atoi(argv[i]));
		data[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	error = check_duplicates(data, argc);
	if (argc == 4 && error == 0)
		algorithm3(&stack_a);
	else if (argc <= 6 && argc >= 5 && error == 0)
		algorithm5(&stack_a, &stack_b, argc - 1);
	//system("leaks push_swap");
	return (0);
}
