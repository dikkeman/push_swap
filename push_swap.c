/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 14:22:19 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/10/10 02:45:42 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(int argc)
{
	int	i;
	int counter;

	i = 0;
	counter = 1;
	while (i < argc - 1)
	{
		while (counter < argc - 1)
		{
			if (t_main.data[i] - t_main.data[counter] == 0)
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
	int	i;
	int error;

	i = 1;
	error = 0;
	t_main.data = malloc(sizeof(int *));
	if (argc <= 2)
	{
		write(1, "ERROR! Need more inputs", 5);
		return (0);
	}
	while (i < argc)
	{
		new_node(&t_main.stack_a, ft_atoi(argv[i]));
		t_main.data[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	error = check_duplicates(argc);
	if (argc <= 4 && error == 0)
		algorithm3(&t_main.stack_a);
	else if (argc <= 6 && error == 0)
		algorithm5(argc - 1);
	free_list(t_main.stack_a);
	system("leaks push_swap");
	return (0);
}
