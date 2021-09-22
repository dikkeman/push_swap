/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/22 11:17:43 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/09/22 11:21:07 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

void	*ft_calloc(size_t nitems, size_t n)
{
	void	*result;
	size_t	total;

	total = nitems * n;
	if (nitems == 0 || n == 0)
	{
		n = 1;
		nitems = 1;
	}
	result = malloc(n * nitems);
	if (!result)
		return (NULL);
	ft_bzero(result, total);
	return (result);
}
