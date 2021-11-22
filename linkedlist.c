/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linkedlist.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 19:02:47 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/11/22 19:42:03 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issorted(t_node *head)
{
	while (head->next != NULL)
	{
		if (head->value > head->next->value)
			return (false);
		head = head->next;
	}
	return (true);
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

void	print_tag(t_node *head)
{
	printf("TAGS:\n");
	while (head != NULL)
	{
		printf("%d -> ", head->tag);
		head = head->next;
	}
	printf("NULL\n");
	write(1, "\n", 2);
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

void	add_tag(t_node **head, int value, int tag)
{
	t_node	*new_node;
	t_node	*last_node;

	new_node = malloc(sizeof(t_node));
	last_node = *head;
	new_node->value = value;
	new_node->tag = tag;
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

void	copy_list(t_node **head, t_node *copy)
{
	while (copy != NULL)
	{
		new_node(head, copy->value);
		copy = copy->next;
	}
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
