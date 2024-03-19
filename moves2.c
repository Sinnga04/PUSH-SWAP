/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:16:07 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/18 21:58:50 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stacksorted(t_list *stack)
{
	t_list	*current;

	current = stack;
	while (current != NULL && current->next != NULL)
	{
		if (current->content > current->next->content)
		{
			return (0);
		}
		current = current->next;
	}
	return (1);
}

t_list	*stackissorted(t_list **stack)
{
	t_list	*current;

	current = *stack;
	while (current != NULL && current->next != NULL)
	{
		if (current->content > current->next->content)
		{
			return (current);
		}
		current = current->next;
	}
	return (0);
}

void	ra(t_list **stacka);
void	rb(t_list **stackb);
void	rr(t_list **stacka, t_list **stackb);
void	rra(t_list **stacka);
void	rrb(t_list **stackb);

void	ra_p(t_list **stacka)
{
	ra(stacka);
	indexing(stacka);
	printf("ra\n");
}

void	rb_p(t_list **stackb)
{
	rb(stackb);
	indexing(stackb);
	printf("rb\n");
}

void	rra_p(t_list **stacka)
{
	rra(stacka);
	indexing(stacka);
	printf("rra\n");
}

void	rrb_p(t_list **stackb)
{
	rrb(stackb);
	indexing(stackb);
	printf("rrb\n");
}
