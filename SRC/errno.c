/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errno.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 19:35:01 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/16 19:36:40 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	- MAX_INT + 1 or MIN_INT - 1
*/

int	check_errors(int *data, int argc, char **argv)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
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
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
