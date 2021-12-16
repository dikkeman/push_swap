/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errno.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 19:35:01 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/16 22:34:16 by xvoorvaa      ########   odam.nl         */
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

int	check_duplicates(int argc, char *argv[])
{
	int	i;
	int	counter;

	i = 1;
	counter = 2;
	while (i < argc)
	{
		while (counter < argc)
		{
			if (ft_atoi(argv[i]) - ft_atoi(argv[counter]) == 0)
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

int	check_errors(int argc, char **argv)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (i < argc - 1)
	{
		if (ft_atol(argv[i + 1]) != ft_atoi(argv[i + 1]))
			error = true;
		i++;
	}
	if (check_duplicates(argc, argv) == true)
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
