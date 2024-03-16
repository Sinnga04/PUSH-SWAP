/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:09:05 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/16 19:38:00 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_list	*smallestnumber(t_list *stacka);
t_list *most_cheapest(t_list *stackb);

void	easy_move_b(t_list *stackb)
{
	if (most_cheapest(stackb)->above_median)
	{
		while (most_cheapest(stackb) != stackb)
		{
			printf("most_cheapest %d\n", most_cheapest(stackb)->content);
			rrb(&stackb);
		}
	}
	else if (!(most_cheapest(stackb)->above_median))
	{
		while (most_cheapest(stackb) != stackb)
		{
			printf("most_cheapest %d\n", most_cheapest(stackb)->content);
			rb(&stackb);
		}
	}
}

void	easy_move_a(t_list *stacka)
{

	if (most_cheapest(stacka)->above_median)
	{
		while (most_cheapest(stacka) != stacka)
		{
			printf("most_cheapest %d\n", most_cheapest(stacka)->content);
			rra(&stacka);
		}
	}
	else if (!(most_cheapest(stacka)->above_median))
	{
		while (most_cheapest(stacka) != stacka)
		{
			printf("most_cheapest %d\n", most_cheapest(stacka)->content);
			ra(&stacka);
		}
	}
}
void	rr_help(t_list **stacka, t_list **stackb)
{
	ra(stacka);
	rb(stackb);
}
void	rr(t_list **stacka, t_list **stackb)
{
	t_list	*current_a;
	t_list	*current_b;
	t_list	*cheapest;

	current_a = *stacka;
	current_b = *stackb;
	cheapest = most_cheapest(*stackb);
	while (current_b != cheapest && current_a != cheapest->target)
		rr_help(stacka, stackb);
	indexing(stacka);
	indexing(stackb);
}

void	rrr_help(t_list	**stacka, t_list **stackb)
{
	rra(stacka);
	rrb(stackb);
}
void	rrr(t_list **stacka, t_list **stackb)
{
	t_list	*current_a;
	t_list	*current_b;
	t_list	*cheapest;

	current_a = *stacka;
	current_b = *stackb;
	cheapest = most_cheapest(*stackb);
	while (current_b != cheapest && current_a != cheapest->target)
		rrr_help(stacka, stackb);
	indexing(stacka);
	indexing(stackb);
}

void	move_nodes(t_list **stacka, t_list **stackb)
{
	t_list	*cheapest;

		cheapest = most_cheapest(*stackb);
		while (cheapest != *stackb && cheapest->target != *stacka)
		{
			if (cheapest->above_median && cheapest->target->above_median)
			{
				rr(stacka, stackb);
			}
			else if (!(cheapest->above_median)
				&& !(cheapest->target->above_median))
			{
				rrr(stacka, stackb);
			}
		}
		easy_move_a(*stacka);
		easy_move_b(*stackb);
		pa(stacka, stackb);
		
}
