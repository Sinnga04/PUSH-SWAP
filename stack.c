/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:11:21 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/19 00:41:22 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*createnode(int content)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (newnode == NULL)
		exit(EXIT_FAILURE);
	newnode->content = content;
	newnode->above_median = 0;
	newnode->index = 0;
	newnode->cost = 0;
	newnode->cheapest = 0;
	newnode->next = NULL;
	newnode->target = NULL;
	return (newnode);
}

void	push(t_list **stack, int value)
{
	t_list	*new_node;

	new_node = createnode(value);
	if (new_node == NULL)
		return ;
	new_node->content = value;
	new_node->next = *stack;
	*stack = new_node;
}

int	empty(t_list *stack)
{
	return (stack == NULL);
}

t_list	*smallestnumber(t_list *stacka)
{
	t_list	*current;
	t_list	*smallest;

	current = stacka;
	smallest = stacka;
	while (current != NULL)
	{
		if (current->content < smallest->content)
			smallest = current;
		current = current->next;
	}
	return (smallest);
}

t_list	*biggestnumber(t_list *stacka)
{
	t_list *current;
	t_list *biggest;

	current = stacka;
	biggest = stacka;
	while (current != NULL)
	{
		if (current->content > biggest->content)
			biggest = current;
		current = current->next;
	}
	return (biggest);
}