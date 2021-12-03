/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tree_sort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/29 14:53:48 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/03 17:36:29 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	I will use the Tree Sort.
	The tree sort will start with a "Root Number".
	This root number will be the start of your tree.
	If the number is lower than the root,
	it will go to the left, else to the right. After you sorted every number,
	you will go to the most left number. The most leftish number is the smallest.
	And the rightest is the highest.

	Here you can see an example:

			15
		11		20
	10		13		23

	You will place in order all the tags.
	The lowest getting the first tag and the highest getting the last tag.

	EXAMPLE:
	VALUE -> 12 11 09 13 06
	TAGS  -> 03 02 01 04 00
*/

int	ft_length_list(t_node *stack_a)
{
	int tag;

	tag = 0;
	while (stack_a != NULL)
	{
		tag++;
		stack_a =stack_a->next;
	}
	return (tag);
}

void	index_values(t_tree *head, int *tag)
{
	if (head != NULL)
	{
		index_values(head->left, tag);
		head->list->tag = *tag;
		(*tag)--;
		index_values(head->right, tag);
		free(head);
	}
}

int	insert_branch(t_tree *head, t_node *stack, int left_true)
{
	t_tree	*new_branch;

	new_branch = ft_calloc(sizeof(t_tree), 1);
	if (!new_branch)
		return (-1);
	new_branch->list = stack;
	new_branch->left = NULL;
	new_branch->right = NULL;
	if (left_true == true)
		head->left = new_branch;
	else
		head->right = new_branch;
	return (0);
}

int	make_branch(t_tree *head, t_node *stack)
{
	int	malloc_protect;

	malloc_protect = 0;
	if (head->list->value > stack->value)
	{
		if (head->left == NULL)
			malloc_protect = insert_branch(head, stack, true);
		else
			make_branch(head->left, stack);
	}
	else if (head->list->value < stack->value)
	{
		if (head->right == NULL)
			malloc_protect = insert_branch(head, stack, false);
		else
			make_branch(head->right, stack);
	}
	return (malloc_protect);
}

int	tree_sort(t_node **stack_a)
{
	int		tag;
	int		malloc_protect;
	t_tree	*root;
	t_node	*main_list;

	tag = ft_length_list(*stack_a);
	root = ft_calloc(sizeof(t_tree), 1);
	if (!root)
		return (-1);
	main_list = *stack_a;
	root->list = main_list;
	root->left = NULL;
	root->right = NULL;
	while (main_list->next != NULL)
	{
		main_list = main_list->next;
		malloc_protect = make_branch(root, main_list);
		if (malloc_protect == -1)
			return (-1);
	}
	index_values(root, &tag);
	*stack_a = root->list;
	return (0);
}
