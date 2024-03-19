/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:54:57 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/18 22:11:07 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list **stackb)
{
	t_list	*top;
	t_list	*temp;

	top = *stackb;
	if (top == NULL || top->next == NULL)
		return ;
	temp = top;
	top = top->next;
	top->next = temp;
	printf("sb\n");
}

void	sa(t_list **stacka)
{
	t_list	*current;

	current = *stacka;
	if (current == NULL || current->next == NULL)
		return ;
	*stacka = current->next;
	current->next = (*stacka)->next;
	(*stacka)->next = current;
	printf("sa\n");
}

void	ra(t_list **stacka)
{
	t_list	*last;

	if (*stacka == NULL || (*stacka)->next == NULL)
	{
		return ;
	}
	last = *stacka;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = *stacka;
	*stacka = (*stacka)->next;
	last->next->next = NULL;
	indexing(stacka);
}

void	rb(t_list **stackb)
{
	t_list	*last;

	if (*stackb == NULL || (*stackb)->next == NULL)
	{
		return ;
	}
	last = *stackb;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = *stackb;
	*stackb = (*stackb)->next;
	last->next->next = NULL;
	indexing(stackb);
}

void	rrb(t_list **stackb)
{
	t_list	*current;
	t_list	*last;

	current = *stackb;
	last = NULL;
	if (*stackb == NULL || (*stackb)->next == NULL)
		return ;
	while (current->next != NULL)
	{
		last = current;
		current = current->next;
	}
	last->next = NULL;
	current->next = *stackb;
	*stackb = current;
	indexing(stackb);
}
