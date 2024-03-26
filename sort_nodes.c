/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:09:05 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/26 13:37:42 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	easy_move_b(t_list **stackb, t_list *small)
{
	if (small->above_median)
		while (*stackb != small)
			rb_p(stackb);
	else
		while (*stackb != small)
			rrb_p(stackb);
}

void	easy_move_a(t_list **stacka, t_list *node)
{
	if (node->above_median)
		while (*stacka != node)
			ra_p(stacka);
	else
		while (*stacka != node)
			rra_p(stacka);
}

void	rr(t_list **stacka, t_list **stackb)
{
	ra(stacka);
	rb(stackb);
	indexing(stacka);
	indexing(stackb);
	printf("rr\n");
}

void	rrr(t_list **stacka, t_list **stackb)
{
	rra(stacka);
	rrb(stackb);
	indexing(stacka);
	indexing(stackb);
	printf("rrr\n");
}

void	move_nodes(t_list **stacka, t_list **stackb)
{
	t_list	*cheap;

	cheap = most_cheapest(*stacka, *stackb);
	if (cheap->above_median && cheap->target->above_median)
	{
		while (cheap != *stackb && cheap->target != *stacka)
			rr(stacka, stackb);
	}
	else if (!(cheap->above_median) && !(cheap->target->above_median))
	{
		while (cheap != *stackb && cheap->target != *stacka)
			rrr(stacka, stackb);
	}
	easy_move_a(stacka, cheap->target);
	easy_move_b(stackb, cheap);
	indexing(stacka);
	indexing(stackb);
	pa(stacka, stackb);
}
