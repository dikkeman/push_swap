/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linkedlist.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/22 13:34:04 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/09/23 18:38:43 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(struct s_node *head)
{
	struct s_node	*temp;

	temp = head;
	printf("\n");
	while (temp != NULL)
	{
		printf("%d -> ", temp->value);
		temp = temp->next;
	}
	printf("NULL\n");
}

void	create_s_node(struct s_node **head, int number)
{
	struct s_node	*new_s_node;
	struct s_node	*last_s_node;

	new_s_node = malloc(sizeof(struct s_node));
	last_s_node = *head;
	new_s_node->value = number;
	new_s_node->next = NULL;
	if (*head == NULL)
		*head = new_s_node;
	else
	{
		while (last_s_node->next != NULL)
			last_s_node = last_s_node->next;
		last_s_node->next = new_s_node;
	}
}
