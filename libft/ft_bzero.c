/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:48:24 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/11/30 20:33:33 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *str, size_t n)
{
	unsigned long	i;
	char			*casted_str;

	i = 0;
	casted_str = (char *) str;
	while (n > i)
	{
		casted_str[i] = 0;
		i++;
	}
}
