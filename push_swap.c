/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 14:22:19 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/09/15 18:53:56 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		write(1, "ERROR! I need some numbers!\n", 29);
	else
		print_sa(argv);
	return (0);
}
