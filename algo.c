/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:38:15 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/19 10:50:01 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_list **stack)
{
	int		i;
	t_list	*current;

	current = *stack;
	i = 0;
	while (*stack)
	{
		(*stack)->index = i++;
		*stack = (*stack)->next;
	}
	*stack = current;
}

void	median(t_list **stack)
{
	t_list	*current;
	int		size;

	size = count(*stack);
	current = *stack;
	while (current)
	{
		current->above_median = (current->index < size / 2);
		current = current->next;
	}
}

int	count(t_list *stack)
{
	int		i;
	t_list	*current;

	i = 0;
	current = stack;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}

void	cost(t_list **stack)
{
	int		size;
	t_list	*current;

	size = count(*stack);
	current = *stack;
	while (current)
	{
		if (current->above_median)
		{
			current->cost = current->index;
		}
		else
			current->cost = size - current->index;
		current = current->next;
	}
}

void	init_stack(t_list **stacka, t_list **stackb)
{
	indexing(stacka);
	indexing(stackb);
	median(stacka);
	median(stackb);
	cost(stackb);
	cost(stacka);
	target_check(stacka, stackb);
	most_cheapest(*stackb);
}

// void	check_all(t_list **stacka, t_list **stackb)
// {
// 	// init_stack(stacka, stackb);

// 	cheapest(*stackb);
// 	move_nodes(stacka, stackb);
// }
