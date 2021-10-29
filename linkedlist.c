/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linkedlist.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 19:02:47 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/10/29 15:37:07 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorting_check(t_node *head)
{
	while (head->next != NULL)
	{
		if (head->value > head->next->value)
			return (TRUE);
		head = head->next;
	}
	return (FALSE);
}

void	free_list(t_node *head)
{
	t_node	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	print_list(t_node *head)
{
	printf("\n");
	while (head != NULL)
	{
		printf("%d -> ", head->value);
		head = head->next;
	}
	printf("NULL\n");
	write(1, "\n", 2);
}

void	new_node(t_node **head, int number)
{
	t_node	*new_node;
	t_node	*last_node;

	new_node = malloc(sizeof(t_node));
	last_node = *head;
	new_node->value = number;
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new_node;
	}
}
