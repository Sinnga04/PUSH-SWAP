/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:34:25 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/26 13:01:27 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorthree(t_list **stacka)
{
	t_list	*big;

	big = biggestnumber(*stacka);
	if (*stacka == big)
		ra_p(stacka);
	else if ((*stacka)->next == big)
		rra_p(stacka);
	if ((*stacka)->content > (*stacka)->next->content)
		sa(stacka);
}

void	small_to_top(t_list **stacka)
{
	t_list	*small;

	small = smallestnumber(*stacka);
	if (small->above_median)
		while (*stacka != small)
			ra_p(stacka);
	else
		while (*stacka != small)
			rra_p(stacka);
}

void	rra(t_list **stacka)
{
	t_list	*current;
	t_list	*last;

	current = *stacka;
	last = NULL;
	if (*stacka == NULL || (*stacka)->next == NULL)
		return ;
	while (current->next != NULL)
	{
		last = current;
		current = current->next;
	}
	last->next = NULL;
	current->next = *stacka;
	*stacka = current;
	indexing(stacka);
}

void	pa(t_list **stacka, t_list **stackb)
{
	t_list	*node;

	node = *stackb;
	if (*stackb == NULL)
		return ;
	*stackb = (*stackb)->next;
	if (*stacka == NULL)
	{
		*stacka = node;
		node->next = NULL;
	}
	else
	{
		node->next = *stacka;
		*stacka = node;
	}
	indexing(stacka);
	indexing(stackb);
	median(stacka);
	median(stackb);
	cost(stackb);
	cost(stacka);
	printf("pa\n");
}

void	pb(t_list **stacka, t_list **stackb)
{
	t_list	*node;

	node = *stacka;
	if (*stacka == NULL)
		return ;
	*stacka = (*stacka)->next;
	if (*stackb == NULL)
	{
		*stackb = node;
		node->next = NULL;
	}
	else
	{
		node->next = *stackb;
		*stackb = node;
	}
	indexing(stacka);
	indexing(stackb);
	median(stacka);
	median(stackb);
	cost(stackb);
	cost(stacka);
	printf("pb\n");
}
