/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:00:14 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/19 01:06:00 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_check(t_list **stacka, t_list **stackb)
{
	t_list	*current_b;
	t_list	*current_a;
	t_list	*nearest_bigger;

	current_b = *stackb;
	while (current_b)
	{
		current_a = *stacka;
		nearest_bigger = NULL;
		while (current_a)
		{
			if (current_b->content > biggestnumber(*stacka)->content)
				nearest_bigger = smallestnumber(*stacka);
			else if (current_a->content > current_b->content)
			{
				if (!nearest_bigger || current_a->content < nearest_bigger->content)
					nearest_bigger = current_a;
			}
			current_a = current_a->next;
		}
		current_b->target = nearest_bigger;
		current_b = current_b->next;
	}
}

void	target_a(t_list **stacka)
{
	t_list	*current_a;
	t_list	*nearest_bigger;

	current_a = *stacka;
	nearest_bigger = NULL;
    while (current_a)
    {
        if (current_a->content > biggestnumber(*stacka)->content)
        {
            nearest_bigger = smallestnumber(*stacka);
        }
        else if (current_a->next && current_a->content < current_a->next->content)
        {
            if (!nearest_bigger || current_a->content < nearest_bigger->content)
                nearest_bigger = current_a;
        }
        current_a = current_a->next;
    }
    (*stacka)->target = nearest_bigger;
}

void	cheapest(t_list **stackb)
{
	t_list	*current_b;
	current_b = *stackb;
	// current_b->cheapest = 0;
	while (current_b && current_b->target)
	{
		current_b->cheapest = current_b->target->cost + current_b->cost;
		current_b = current_b->next;
	}
}

t_list	*most_cheapest(t_list *stackb)
{
	t_list	*cheap;
	int		sum;

	cheapest(&stackb);
	sum = stackb->cheapest;
	cheap = stackb;
	while (stackb)
	{
		if (stackb->cheapest < sum)
		{
			cheap = stackb;
			sum = cheap->cheapest;
		}
		stackb = stackb->next;
	}
	return (cheap);
}

// t_list *cheapest(t_list *stackb)
// {
// 	t_list *current_b;
	
// 	current_b = stackb;
// 	while (stackb)
// 	{
// 		if(current_b->target->cost + current_b->cost < stackb->cost + stackb->target->cost)
// 			current_b = stackb;
// 		stackb = stackb->next;
// 	}
// 	return (current_b);
// }

int	pop(t_list **stack)
{
	int		value;
	t_list	*temp;

	if (*stack == NULL)
		printf("error\n");
	value = (*stack)->content;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
	return (value);
}
