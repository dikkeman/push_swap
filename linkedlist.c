/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linkedlist.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/22 13:34:04 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/09/22 18:30:57 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void create_node(struct node **head, int number)
{
	struct node *new_node;

	new_node = malloc(sizeof(struct node));
	new_node->value = number;
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
    else
    {
        struct node *lastNode = *head;

        while(lastNode->next != NULL)
            lastNode = lastNode->next;
        lastNode->next = new_node;
    }
}

void linkedlist(int argc)
{
	struct node *head;
	struct node *temp;
	int i;

	i = 0;
	head = NULL;
	while (i < argc)
	{
		create_node(&head, i);
		i++;
	}
	temp = head;
	while (temp != NULL)
	{
		printf("%d --> ", temp->value);
		temp = temp->next;
	}
	printf("NULL");
	printf("\n\n");
}
