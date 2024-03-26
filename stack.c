/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:11:21 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/26 13:02:47 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_list	*current;
	t_list	*biggest;

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
