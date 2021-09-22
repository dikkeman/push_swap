/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 14:22:19 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/09/22 18:15:22 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algoritm_3numbers(void)
{
	if (t_main.stack_a[0] > t_main.stack_a[1])
		action_sa();
	if (t_main.stack_b[0] > t_main.stack_b[1])
		action_sb();
	if (t_main.stack_b[0] > t_main.stack_b[1] && t_main.stack_a[0] > t_main.stack_a[1])
		action_ss();
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	t_main.stack_a = (int *) malloc(argc - 1);
	t_main.stack_b = (int *) ft_calloc(argc - 1, sizeof(int));
	linkedlist(argc);
	if (argc <= 2)
	{
		write(1, "ERROR! I need some numbers!\n", 29);
		exit (0);
	}
	else
	{
		printf("BEFORE:\n"); // <- Delete this when I am done!
		while (i < argc)
		{
			t_main.stack_a[i - 1] = ft_atoi(argv[i]);
			printf("%d\n", t_main.stack_a[i - 1]); // <- Delete this when I am done!
			i++;
		}
		printf("\n");
		if (argc < 5)
			algoritm_3numbers();
	}
	/*
		Delete this when i am done.
	 */
	printf("\n");
	i = 0;
	printf("AFTER:\n");
	while(i + 1 < argc)
	{
		printf("%d\n", t_main.stack_a[i]);
		i++;
	}
	free(t_main.stack_a);
	return (0);
}
