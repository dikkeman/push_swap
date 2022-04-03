/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:55:07 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/03 22:15:29 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
