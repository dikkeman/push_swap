/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tree_sort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/29 14:53:48 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/11/24 14:23:43 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	I will need to use Radix Sort, but I will not show it "On screen".
	It will be done in the background. Make a new list and use the "INT TAGS".
	Every number will be sorted and get a tag at the end from 0 - MAX OF ARGC.
	I will bring back every number to its original position with a tag on it.
	With these tags I will sort in stack_a & stack_b.

	EXAMPLE:
	VALUE -> 12 11 09 13 06
	TAGS  -> 03 02 01 04 00
*/

void	index_values(t_tree *head, int *tag)
{
	if (head != NULL)
	{
		index_values(head->left, tag);
		head->list->tag = *tag;
		(*tag)++;
		index_values(head->right, tag);
		free(head);
	}
}

void	insert_branch(t_tree *head, t_node *stack, int left_true)
{
	t_tree	*new_branch;

	new_branch = malloc(sizeof(t_tree));
	new_branch->list = stack;
	new_branch->left = NULL;
	new_branch->right = NULL;
	if (left_true == true)
		head->left = new_branch;
	else
		head->right = new_branch;
}

void	make_branch(t_tree *head, t_node *stack)
{
	if (head->list->value > stack->value)
	{
		if (head->left == NULL)
			insert_branch(head, stack, true);
		else
			make_branch(head->left, stack);
	}
	else if (head->list->value < stack->value)
	{
		if (head->right == NULL)
			insert_branch(head, stack, false);
		else
			make_branch(head->right, stack);
	}
}

void	tree_sort(t_node **stack_a)
{
	int		tag;
	t_tree	*root;
	t_node	*main_list;

	tag = 0;
	root = malloc(sizeof(t_tree));
	main_list = NULL;
	copy_list(&main_list, *stack_a);
	root->list = main_list;
	root->left = NULL;
	root->right = NULL;
	while (main_list->next != NULL)
	{
		main_list = main_list->next;
		make_branch(root, main_list);
	}
	index_values(root, &tag);
	*stack_a = root->list;
}

void	algorithm_radix(t_node **stack_a, t_node **stack_b, int argc)
{
	tree_sort(stack_a);
	printf("SKIP: %d", argc);
	print_list(*stack_a);
	print_tag(*stack_a);
	stack_b = stack_a;
}
