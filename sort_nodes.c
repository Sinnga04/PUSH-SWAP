/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:09:05 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/17 13:21:43 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_list	*smallestnumber(t_list *stacka);
t_list *most_cheapest(t_list *stackb);

void	easy_move_b(t_list **stackb)
{
	t_list *cheap;

	cheap = most_cheapest(*stackb);
	if (cheap->above_median)
	{
		while (cheap != *stackb)
		{
			rb(stackb);
		}
	}
	else if (!(cheap->above_median))
	{
		while (cheap != *stackb)
		{
			rrb(stackb);
		}
	}
}

void	easy_move_a(t_list **stacka, t_list *node)
{
	if (node->above_median)
	{
		while (node != *stacka)
		{
			ra(stacka);
		}
	}
	else if (!(node->above_median))
	{
		while (node != *stacka)
		{
			rra(stacka);
		}
	}
}
void	rr(t_list **stacka, t_list **stackb)
{
	ra(stacka);
	rb(stackb);
	indexing(stacka);
	indexing(stackb);
}

void	rrr(t_list **stacka, t_list **stackb)
{

	rra(stacka);
	rrb(stackb);
	indexing(stacka);
	indexing(stackb);
}

void  small_to_top(t_list **stacka)
{
	t_list *small = smallestnumber(*stacka);

		if (small->above_median)
			while (*stacka != small)
				rra(stacka);
		else
			while (*stacka != small)	
				ra(stacka);
}

void	move_nodes(t_list **stacka, t_list **stackb)
{
	t_list	*cheapest;
	t_list	*small;
	t_list	*biggest;
		cheapest = most_cheapest(*stackb);
		while (cheapest != *stackb && cheapest->target != *stacka)
		{
			if (cheapest->above_median && cheapest->target->above_median)
			{
				ra(stacka);
				rb(stacka);
			}
			else if (!(cheapest->above_median)
				&& !(cheapest->target->above_median))
			{
				rra(stacka);
				rrb(stacka);
			}
		}
		easy_move_a(stacka, cheapest->target);
		easy_move_b(stackb);
		pa(stacka, stackb);
		// small = smallestnumber(*stacka);
		// printf("the smallest number is %d\n", small->content);
		// if (small->above_median)
		// 	while (*stacka != small)
		// 		rra(stacka);
		// else
		// 	while (*stacka != small)	
		// 		ra(stacka);
		// t_list *big = biggestnumber(*stacka);
		// if (big->above_median)
		// 		ra(stacka);
		// else
		// 		rra(stacka);
		
}

