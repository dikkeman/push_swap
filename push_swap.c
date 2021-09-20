/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 14:22:19 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/09/20 18:20:27 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_algoritm(void)
{
	if (t_main.all_numbers[0] < t_main.all_numbers[1])
		print_sa();
	if (t_main.all_numbers[1] < t_main.all_numbers[0])
		print_sb();
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	t_main.all_numbers = (int *) malloc(argc - 1);
	if (argc <= 2)
	{
		write(1, "ERROR! I need some numbers!\n", 29);
		exit (0);
	}
	else
	{
		while (i < argc)
		{
			t_main.all_numbers[i] = ft_atoi(argv[i]);
			i++;
		}
		check_algoritm();
	}
	return (0);
}
